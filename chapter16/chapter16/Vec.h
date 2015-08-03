//
//  Vec.h
//  chapter16
//
//  Created by vividhsu on 8/2/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter16__Vec__
#define __chapter16__Vec__

#include <iostream>
#include <utility>

using namespace std;

template <typename T>
class Vec {
public:
    // constructor
    Vec(): elements(nullptr), first_free(nullptr), cap(nullptr) {}
    // copy constructor
    Vec(const Vec<T>&);
    // copy assignment
    Vec& operator=(const Vec<T>&);
    // destructor
    ~Vec();
    
    // member functions
    void push_back(const T&);
    size_t size() const { return first_free - elements; }
    size_t capacity() const { return cap - elements; }
    T* begin() const { return elements; }
    T* end() const { return first_free; }
private:
    static allocator<T> alloc;
    void chk_n_alloc() {
        if (size() == capacity())
            reallocate();
    }
    pair<T*, T*> alloc_n_copy(const T*, const T*);
    void free();
    void reallocate();
    // members
    T* elements;
    T* first_free;
    T* cap;
};

// definition for the static data member
template <typename T>
allocator<T> Vec<T>::alloc;

template <typename T>
inline pair<T*, T*> Vec<T>::alloc_n_copy(const T* b, const T* e) {
    auto data = alloc.allocate(e - b);
    return {data, uninitialized_copy(b, e, data)};
}

template <typename T>
inline void Vec<T>::free() {
    for (auto p = first_free; p != elements;)
        alloc.destroy(--p);
    if (elements)
        alloc.deallocate(elements, cap - elements);
}

template <typename T>
inline void Vec<T>::reallocate() {
    auto newcapacity = size() ? 2 * size() : 2;
    auto first = alloc.allocate(newcapacity);
    auto dest = first;
    auto elem = elements;
    
    for (size_t i = 0; i != size(); i++) {
        alloc.construct(dest++, std::move(*elem++));
    }
    
    free();
    elements = first;
    first_free = dest;
    cap = elements + newcapacity;
}

template <typename T>
Vec<T>::Vec(const Vec<T>& item) {
    auto newdata = alloc_n_copy(item.begin(), item.end());
    elements = newdata.first;
    first_free = cap = newdata.second;
}

template <typename T>
Vec<T>& Vec<T>::operator=(const Vec<T>& rhs) {
    auto data = alloc_n_copy(rhs.begin(), rhs.end());
    free();
    elements = data.first;
    first_free = cap = data.second;
    return *this;
}

template <typename T>
Vec<T>::~Vec() {
    free();
}

template <typename T>
void Vec<T>::push_back(const T& t) {
    chk_n_alloc();
    alloc.construct(first_free++, t);
}
#endif /* defined(__chapter16__Vec__) */
