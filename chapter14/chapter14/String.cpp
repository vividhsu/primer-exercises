//
//  String.cpp
//  chapter14
//
//  Created by vividhsu on 6/23/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include "String.h"

allocator<char> String::alloc_s;

ostream& operator<<(ostream &os, const String &item) {
    char *c = item.beg;
    while (c != item.end) {
        os << *c++;
    }
    return os;
}