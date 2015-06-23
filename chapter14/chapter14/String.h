//
//  String.h
//  chapter14
//
//  Created by vividhsu on 6/23/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter14__String__
#define __chapter14__String__

#include <iostream>
#include <utility>
#include <memory>


using std::allocator;
using std::pair;
using std::uninitialized_copy;
using std::cout;
using std::endl;
using std::ostream;

class String {
public:
    friend ostream& operator<<(ostream&, const String&);
    // constructor
    String():beg(nullptr), end(nullptr) {}
    String(const char*);
    // copy constructor
    String(const String&);
    // copy-assignment operator
    String& operator=(const String&);
    // move constructor
    String(String &&) noexcept;
    // move assignment operator
    String& operator=(String&&) noexcept;
    //destructor
    ~String();
    
    // member functions
    const char* c_str() const { return beg; };
    size_t size() const { return end - beg; };
    
private:
    // functions for copy control
    pair<char*, char*> alloc_n_copy_s(const char*, const char*);
    void free_s();
    
    // members
    char *beg;
    char *end;
    
    static allocator<char> alloc_s;
};

ostream& operator<<(ostream&, const String&);

inline pair<char*, char*> String::alloc_n_copy_s(const char *a, const char *b) {
    char *newData = alloc_s.allocate(b - a);
    return std::make_pair(newData, uninitialized_copy(a, b, newData));
}

inline void String::free_s() {
    for (auto iter = end; iter != beg; ) {
        alloc_s.destroy(--iter);
    }
    alloc_s.deallocate(beg, end - beg);
}

inline String::String(const char* s) {
    char *sl = const_cast<char*>(s);
    while (*sl)
        ++sl;
    auto data = alloc_n_copy_s(s, ++sl);
    beg = data.first;
    end = data.second;
}

inline String::String(const String &rhs) {
    auto data = alloc_n_copy_s(rhs.beg, rhs.end);
    beg = data.first;
    end = data.second;
    cout << "copy constructor for " <<*beg<< endl;
}


inline String& String::operator=(const String &rhs) {
    auto data = alloc_n_copy_s(rhs.beg, rhs.end);
    free_s();
    beg = data.first;
    end = data.second;
    cout << "copy assignment" << endl;
    return *this;
}

inline String::String(String &&s) noexcept: beg(s.beg), end(s.end) {
    s.beg = s.end = nullptr;
    cout << "move constructor for " <<*beg<< endl;
}

inline String& String::operator=(String &&rhs) noexcept {
    if (this != &rhs) {
        free_s();
        beg = rhs.beg;
        end = rhs.end;
        rhs.beg = rhs.end = nullptr;
    }
    return *this;
}

inline String::~String() {
    free_s();
}



#endif /* defined(__chapter14__String__) */
