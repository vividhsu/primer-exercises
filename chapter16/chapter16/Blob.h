//
//  Blob.h
//  chapter16
//
//  Created by vividhsu on 8/1/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter16__Blob__
#define __chapter16__Blob__

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <initializer_list>

using namespace std;

template <typename T> class BlobPtr;
template <typename T> class Blob;
template <typename T> bool operator==(const Blob<T>&, const Blob<T>&);

template <typename T>
class Blob {
    friend class BlobPtr<T>;
    friend bool operator==<T>(const Blob<T>&, const Blob<T>&);
public:
    typedef typename vector<T>::size_type size_type;
    // constructor
    Blob();
    Blob(initializer_list<T> il);
    
    // number of elements in the Blob
    size_type size() const { return data -> size(); }
    bool empty() const { return data -> empty(); }
    
    // add and remove elements
    void push_back(const T& t) { data -> push_back(t); }
    void push_back(T&& t) { data -> push_back(std::move(t)); }
    void pop_back();
    
    // element access
    T& front();
    T& back();
    T& at(size_type);
    const T& front() const;
    const T& back() const;
    const T& at(size_type) const;
    T& operator[](size_type);
    const T& operator[](size_type) const;
    
    
private:
    // throw msg if access to a not exist position
    void check(size_type i, const string& msg) const;
    
    shared_ptr<vector<T>> data;
};

// constructor
template <typename T>
Blob<T>::Blob(): data(make_shared<vector<T>>()) {}

template <typename T>
Blob<T>::Blob(initializer_list<T> il): data(make_shared<vector<T>>(il)) {}


// check members
template <typename T>
void Blob<T>::check(size_type i, const string& msg) const {
    if (i > data -> size())
        throw out_of_range(msg);
}

// remove element
template <typename T>
void Blob<T>::pop_back() {
    check(0, "pop back from empty Blob");
    data -> pop_back();
}

// element access
template <typename T>
T& Blob<T>::front() {
    check(0, "front on empty Blob");
    return data -> front();
}

template <typename T>
T& Blob<T>::back() {
    check(0, "back on empty Blob");
    return data -> back();
}

template <typename T>
const T& Blob<T>::front() const {
    check(0, "front on empty Blob");
    return data -> front();
}

template <typename T>
const T& Blob<T>::back() const {
    check(0, "back on empty Blob");
    return data -> back();
}

template <typename T>
T& Blob<T>::at(size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
const T& Blob<T>::at(size_type i) const {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
T& Blob<T>::operator[](size_type i) {
    check(i, "subscript out of range");
    return (*data)[i];
}

template <typename T>
const T& Blob<T>::operator[](size_type i) const {
    check(i, "subscript out of range");
    return (*data)[i];
}

// operator
template <typename T>
bool operator==(const Blob<T>& lhs, const Blob<T>& rhs) {
    if (rhs.size() != lhs.size())
        return false;
    for (size_t i = 0; i < rhs.size(); i++) {
        if (lhs[i] != rhs[i])
            return false;
    }
    return true;
}


template <typename T>
bool operator==(const BlobPtr<T>&, const BlobPtr<T>&);

template <typename T>
class BlobPtr {
    friend bool operator==<T>(const BlobPtr<T>&, const BlobPtr<T>&);
public:
    // constructor
    BlobPtr();
    BlobPtr(Blob<T> &a, size_t sz = 0): wptr(a.data), curr(sz) {}
    
    T& operator*() const {
        auto p = check(curr, "dereference past end");
        return (*p)[curr];
    }
    
    BlobPtr<T> operator++();
    BlobPtr<T> operator--();
    
    BlobPtr<T> operator++(int);
    BlobPtr<T> operator--(int);
private:
    // check returns a shared_ptr to the vector if check succeed
    shared_ptr<vector<T>> check(size_t, const string&) const;
    
    weak_ptr<vector<T>> wptr;
    size_t curr;
};

template <typename T>
shared_ptr<vector<T>> BlobPtr<T>::check(size_t i, const string& msg) const {
    auto ret = wptr.lock();
    if (!ret)
        throw runtime_error("unbound BlobPtr");
    if (i >= ret -> size())
        throw out_of_range(msg);
    return ret;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++() {
    check(curr, "increment past end of BlobPtr");
    ++curr;
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--() {
    --curr;
    check(-1, "increment past end of BlobPtr");
    return *this;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator++(int) {
    auto temp = *this;
    ++*this;
    return temp;
}

template <typename T>
BlobPtr<T> BlobPtr<T>::operator--(int) {
    auto temp = *this;
    --*this;
    return temp;
}

template <typename T>
bool operator==(const BlobPtr<T>& lhs, const BlobPtr<T>& rhs) {
    return lhs.wptr.lock().get() == rhs.wptr.lock().get() && lhs.curr == rhs.curr;
}

#endif /* defined(__chapter16__Blob__) */
