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
#include <string>
#include <memory>
#include <initialized_list>

using std::vector;
using std::string;
using std::out_of_range;
using std::shared_ptr;
using std::initialized_list;

class strBlob{
public:
    typedef vector<string>::size_type size_type;
    //constructor
    strBlob();
    strBlob(initialized_list<string> il);
    
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
strBlob::strBlob(initialized_list<string> il): data(make_shared<vector<string>>(il)) {}

void strBlob::check(size_type i, const string& msg){
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

#endif
