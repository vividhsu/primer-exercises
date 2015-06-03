//
//  HasPtr_pointerlike.h
//  chapter13
//
//  Created by vividhsu on 6/2/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef chapter13_HasPtr_pointerlike_h
#define chapter13_HasPtr_pointerlike_h

#include <iostream>
#include <string>

using std::string;

class HasPtr_pointerlike {
public:
    // constructor
    HasPtr_pointerlike(const string &s = string()): ps(new string(s)), i(0), use(new size_t(1)) {}
    // copy-constructor
    HasPtr_pointerlike(const HasPtr_pointerlike &orig): ps(orig.ps), i(orig.i), use(orig.use) { ++*use; }
    //copy-assignment operator
    HasPtr_pointerlike& operator=(HasPtr_pointerlike&);
    //destructor
    ~HasPtr_pointerlike();
private:
    string *ps;
    int i;
    size_t *use;
};

HasPtr_pointerlike::~HasPtr_pointerlike(){
    if(--*use == 0){
        delete ps;
        delete use;
    }
}

HasPtr_pointerlike& HasPtr_pointerlike::operator=(HasPtr_pointerlike &rhs){
    ++*rhs.use;
    if(--*use == 0){
        delete ps;
        delete use;
    }
    ps = rhs.ps;
    i = rhs.i;
    use = rhs.use;
    return *this;
}

#endif
