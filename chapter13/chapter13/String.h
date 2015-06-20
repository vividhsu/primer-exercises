//
//  String.h
//  chapter13
//
//  Created by vividhsu on 6/6/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter13__String__
#define __chapter13__String__

#include <iostream>
#include <utility>

using std::allocator;

class String {
public:
    // constructor
    String():beg(nullptr), end(nullptr) {}
    String(const char*);
    // copy constructor
    String(const String&);
    // copy-assignment operator
    String& operator=(const String&);
    //destructor
    ~String();
    
    // member functions
    const char* c_str() const;
    size_t size() const;
    
private:
    // functions for copy control
    
    
    // members
    char *beg;
    char *end;
    
    static allocator<char> alloc;
};

#endif /* defined(__chapter13__String__) */
