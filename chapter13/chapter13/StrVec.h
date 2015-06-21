//
//  StrVec.h
//  chapter13
//
//  Created by vividhsu on 6/6/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter13__StrVec__
#define __chapter13__StrVec__

#include <iostream>
#include <string>
#include <memory>
#include <utility>
#include <algorithm>

using std::string;
using std::allocator;
using std::pair;
using std::uninitialized_copy;
using std::initializer_list;

class StrVec {
public:
    //constructor
    StrVec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    StrVec(initializer_list<string>);
    // copy constructor
    StrVec(const StrVec&);
    // copy assignment operation
    StrVec& operator=(const StrVec &);
    // move constructor
    StrVec(StrVec &&) noexcept;
    // move assignment opearation
    StrVec& operator=(StrVec &&) noexcept;
    // destructor
    ~StrVec();
    
    //member functions
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    string *begin() const { return elements; }
    string *end() const { return first_free; }
    void push_back(const string&);
    void reserve(size_t n);
    void resize(size_t n);
    void resize(size_t n, const string&);
    
private:
    // functions for copy control
    void chk_n_alloc() { if (size() == capacity()) reallocate(); }
    pair<string*, string*> alloc_n_copy(const string*, const string*);
    void free();
    void reallocate();
    
    // members
    string *elements;
    string *first_free;
    string *cap;
    
    static allocator<string> alloc;   // declaration
};

inline pair<string*, string*> StrVec::alloc_n_copy(const string *b, const string *e) {
    string* data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

inline void StrVec::free() {
    /**
    if (elements) {
        for (auto p = first_free; p != elements; ) {
            alloc.destroy(--p);
        }
        alloc.deallocate(elements, cap - elements);
    }
    */
    for_each(elements, first_free, [](string &p) { alloc.destroy(&p); });
    alloc.deallocate(elements, cap - elements);
}

inline void StrVec::reallocate() {
    size_t newCap = size() ? 2 * size() : 1;
    string *data = alloc.allocate(newCap);
    string *dest = data;      // points to the next free position in the new array
    string *elem = elements;  // points to the next elements in the old array
    for (auto i = 0 ; i < size(); i++) {
        alloc.construct(dest++, std::move(*elem++));
    }
    free();
    elements = data;
    first_free = dest;
    cap = elements + newCap;
}

inline StrVec::StrVec(initializer_list<string> il) {
    pair<string*, string*> data = alloc_n_copy(il.begin(), il.end());
    elements = data.first;
    first_free = data.second;
    cap = data.second;
}

inline StrVec::StrVec(const StrVec &rhs) {
    pair<string*, string*> data = alloc_n_copy(rhs.elements, rhs.first_free);
    elements = data.first;
    first_free = data.second;
    cap = data.second;
}

inline StrVec::StrVec(StrVec &&s) noexcept : elements(s.elements), first_free(s.first_free), cap(s.cap) {
    s.elements = nullptr;
    s.first_free = nullptr;
    s.cap = nullptr;
}

inline StrVec::~StrVec() {
    free();
}

inline StrVec& StrVec::operator=(const StrVec &rhs) {
    pair<string*, string*> data = alloc_n_copy(rhs.elements, rhs.first_free);
    free();
    elements = data.first;
    first_free = data.second;
    cap = data.second;
    return *this;
}

inline StrVec& StrVec::operator=(StrVec &&rhs) noexcept {
    if (this != &rhs) {
        free();
        elements = rhs.elements;
        first_free = rhs.first_free;
        cap = rhs.cap;
        rhs.elements = rhs.first_free = rhs.cap = nullptr;
    }
    return *this;
}

inline void StrVec::push_back(const string &s) {
    chk_n_alloc();
    alloc.construct(first_free++, s);
    
}

inline void StrVec::reserve(size_t n) {
    if (n < capacity())
        return;
    reallocate();
}

inline void StrVec::resize(size_t n, const string &s) {
    if (n < size()) {
        while (first_free != elements + n) {
            alloc.destroy(--first_free);
        }
    }
    else if (n > size()) {
        for (auto i = size(); i != n; i++) {
            alloc.construct(first_free++, s);
        }
    }
    else if (n > capacity()) {
        reallocate();
        for (auto i = size(); i != n; i++) {
            alloc.construct(first_free++, s);
        }
    }
}

#endif /* defined(__chapter13__StrVec__) */
