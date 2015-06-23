//
//  main.cpp
//  chapter14
//
//  Created by vividhsu on 6/21/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include <iostream>

#include "String.h"
#include "Sales_data.h"

using std::cout;
using std::endl;
using std::cin;


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


void ex14_06() {
    cout << "-----ex14.6-----" << endl;
    
}

void ex14_07() {
    cout << "-----ex14.7-----" << endl;
    String a("abv");
    cout << a << endl;
}

void ex14_09() {
    cout << "-----ex14.9-----" << endl;
    
}

void ex14_10() {
    cout << "-----ex14.10-----" << endl;
    /**
    (a) bookNo = "0-201-99999-9"
        unit_sold = 10
        revenue = 249.5
    (b) bookNo = "10"
        unit_sold = 24
        revenue = 22.8
    */
    Sales_data a;
    cin >> a;
    cout << a << endl;
}

void ex14_11() {
    cout << "-----ex14.11-----" << endl;
    // no input fail check
}

int main(int argc, const char * argv[]) {
//    ex14_01();
//    ex14_02();
//    ex14_03();
//    ex14_04();
//    ex14_06();
//    ex14_07();
//    ex14_09();
//    ex14_10();
//    ex14_11();
    return 0;
}
