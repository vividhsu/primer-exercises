//
//  StrBlob.h
//  chapter13
//
//  Created by vividhsu on 6/2/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef chapter13_StrBlob_h
#define chapter13_StrBlob_h

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

class strBlob{
public:
    typedef vector<string>::size_type size_type;

    //constructor
    strBlob();
    strBlob(initializer_list<string> il);
    
    //copy-constructor
    strBlob(const strBlob& orig): data(make_shared<vector<string>>(*orig.data)) {}
    
    //copy-assignment operator
    strBlob& operator=(const strBlob &rhs){
        shared_ptr<vector<string>> temp = make_shared<vector<string>>(*rhs.data);
        data = temp;
        return *this;
    }
    
    void push_back(string &&s) { data -> push_back(std::move(s)); }
    
private:
    //members
    shared_ptr<vector<string>> data;

};


#endif
