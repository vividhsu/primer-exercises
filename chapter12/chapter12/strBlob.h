//
//  strBlob.h
//  chapter12
//
//  Created by vividhsu on 5/27/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef chapter12_strBlob_h
#define chapter12_strBlob_h

#include <iostream>
#include <vector>
#include <exception>
#include <stdexcept>
#include <string>
#include <memory>
#include <initializer_list>

using std::vector;
using std::string;
using std::out_of_range;
using std::shared_ptr;
using std::initializer_list;
using std::make_shared;
using std::weak_ptr;
using std::runtime_error;

class strBlobPtr;

class strBlob{
public:
    typedef vector<string>::size_type size_type;
    friend class strBlobPtr;
    strBlobPtr begin();
    strBlobPtr end();
    //constructor
    strBlob();
    strBlob(initializer_list<string> il);
    
    size_type size() const { return data -> size(); }
    bool empty() const { return data -> empty(); }
    
    void push_back(const string& t) { data -> push_back(t); }
    void pop_back();
    
    string& front();
    string& back();
    const string& front() const;
    const string& back() const;
private:
    //members
    shared_ptr<vector<string>> data;
    
    void check(size_type i, const string& msg) const;
};

strBlob::strBlob(): data(make_shared<vector<string>>()) {}
strBlob::strBlob(initializer_list<string> il): data(make_shared<vector<string>>(il)) {}

void strBlob::check(size_type i, const string& msg) const{
    if (i >= data -> size()) {
        throw out_of_range(msg);
    }
}

void strBlob::pop_back(){
    check(0, "pop_back on empty strBlob");
    data -> pop_back();
}

string& strBlob::front(){
    check(0, "front on empty strBlob");
    return data -> front();
}

const string& strBlob::front() const {
    check(0, "front on empty strBlob");
    return data -> front();
}

string& strBlob::back() {
    check(0, "back on empty strBlob");
    return data -> back();
}

const string& strBlob::back() const {
    check(0, "back on empty strBlob");
    return data -> back();
}

class strBlobPtr{
    friend bool eq(const strBlobPtr&, const strBlobPtr&);
public:
    strBlobPtr():curr(0) {}
    strBlobPtr(strBlob& a, size_t sz = 0): wptr(a.data), curr(sz) {}
    string& deref() const;
    strBlobPtr& incr();
    
private:
    shared_ptr<vector<string>>& check(size_t, const string&) const;
    weak_ptr<vector<string>> wptr;
    size_t curr;
};

shared_ptr<vector<string>>& strBlobPtr::check(size_t i, const string& msg) const{
    auto ret = wptr.lock();
    if(!ret){
        throw runtime_error("unbound strBlobPtr");
    }
    if (i >= ret -> size()) {
        throw out_of_range(msg);
    }
    return ret;
}

string& strBlobPtr::deref() const {
    auto p = check(curr, "dereference past end");
    return (*p)[curr];
}

strBlobPtr& strBlobPtr::incr(){
    check(curr, "increment past end");
    ++curr;
    return *this;
}

strBlobPtr strBlob::begin(){
    return strBlobPtr(*this);
}

strBlobPtr strBlob::end(){
    return strBlobPtr(*this, data -> size());
}

bool eq(const strBlobPtr& lhs, const strBlobPtr& rhs){
    auto l = lhs.wptr.lock();
    auto r = rhs.wptr.lock();
    if(l == r)
        return (!r || lhs.curr == rhs.curr);
    else
        return false;
}

bool neq(const strBlobPtr& lhs, const strBlobPtr& rhs){
    return !eq(lhs, rhs);
}
#endif
