//
//  debug_rep.h
//  chapter16
//
//  Created by vividhsu on 8/23/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter16__debug_rep__
#define __chapter16__debug_rep__

#include <iostream>
#include <string>
#include <sstream>

using namespace::std;

template <typename T> string debug_rep(const T &t);

template <typename T> string debug_rep(T* p);

string debug_rep(const string &s);

//string debug_rep(char *p);

//string debug_rep(const char *p);

#endif /* defined(__chapter16__debug_rep__) */
