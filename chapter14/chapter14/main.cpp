//
//  main.cpp
//  chapter14
//
//  Created by vividhsu on 6/21/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include <iostream>

#include "Sales_data.h"

using std::cout;
using std::endl;


void ex14_01() {
    cout << "-----ex14.1-----" << endl;
    cout << "overloaded operator vs. build-in operator: \n";
    cout << "same: An overloaded operator has the same precedence and associativity as the corresponding build-in operator. \n";
    cout << "diff: 1. we can call the overloaded operator directly; \n";
    cout << "      2. overloaded \"&&\", \"||\", \",\" operators are not preserved. both operand are always ealuated." << endl;
}

void ex14_02() {
    cout << "-----ex14.2-----" << endl;
    
}

void ex14_03() {
    cout << "-----ex14.3-----" << endl;
    /**
    (a) "cobble" == "stone"
    both are char*, built-in type, use built-in ==
    (b) svec1[0] == svec2[0]
    both are strings, use string overloaded ==
    (c) svec1 == svec2
    both are vectors, use vector overloaded ==
    (d) svec1[0] == "stone"
    left one is string, right one is char*, use string overloaded ==
    */
}

void ex14_04() {
    cout << "-----ex14.4-----" << endl;
    /**
    (a) %
    non-member
    (b) %=
    member
    (c) ++
    member
    (d) ->
    member
    (e) <<
    non-member
    (f) &&
    non-member
    (g) ==
    non-member
    (h) ()
    member
    */
}


int main(int argc, const char * argv[]) {
    ex14_01();
    ex14_02();
    ex14_03();
    ex14_04();
    
    return 0;
}
