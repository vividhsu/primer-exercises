//
//  HasPtr.h
//  chapter13
//
//  Created by vividhsu on 6/1/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef chapter13_HasPtr_h
#define chapter13_HasPtr_h

#include <iostream>
#include <string>

using std::string;

class HasPtr {
public:
    HasPtr(const string &s = string()): ps(new string(s)), i(0) {}
    HasPtr(const HasPtr &orig): ps(orig.ps), i(orig.i) {}
    HasPtr& operator=(const HasPtr &rhs){
        string *temp = new string(*rhs.ps);
        delete ps;
        ps = temp;
        i = rhs.i;
        return *this;
    }
    ~HasPtr() { delete ps; }
private:
    string *ps;
    int i;
};


#endif
