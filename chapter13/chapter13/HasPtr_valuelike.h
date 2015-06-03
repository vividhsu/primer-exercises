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

class HasPtr_valuelike {
public:
    HasPtr_valuelike(const string &s = string()): ps(new string(s)), i(0) {}
    HasPtr_valuelike(const HasPtr_valuelike &orig): ps(new string(*orig.ps)), i(orig.i) {}
    HasPtr_valuelike& operator=(const HasPtr_valuelike &rhs){
        string *temp = new string(*rhs.ps);
        delete ps;
        ps = temp;
        i = rhs.i;
        return *this;
    }
    ~HasPtr_valuelike() { delete ps; }
private:
    string *ps;
    int i;
};


#endif
