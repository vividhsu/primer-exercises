//
//  debug_rep.cpp
//  chapter16
//
//  Created by vividhsu on 8/23/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include "debug_rep.h"

template <typename T>
string debug_rep(const T &t)
{
    cout << "1. take a reference to const object" << endl;
    ostringstream ret;
    ret << t;
    return ret.str();
}

template <typename T>
string debug_rep(T* p)
{
    cout << "2. take a pointer" << endl;
    ostringstream ret;
    ret << "pointer: " << p;
    if (p)
        ret << " " << debug_rep(*p);
    else
        ret << " null pointer";
    return ret.str();
}

string debug_rep(const string &s)
{
    cout << "3. nontemplate, take string" << endl;
    return '"' + s + '"';
}

/**
string debug_rep(char *p)
{
    cout << "4. nontemplate, take char" << endl;
    string str(p);
    return debug_rep(str);
}

string debug_rep(const char *p)
{
    cout << "5. nontemplate, take const char" << endl;
    string str(p);
    return debug_rep(str);
}
*/