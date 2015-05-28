//
//  main.cpp
//  chapter12
//
//  Created by vividhsu on 5/27/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

void ex12_1(){
    cout << "-----ex12.1-----" << endl;
    cout << "b2 is destroyed, but the elements in b2 don't.\n";
    cout << "b1 has 4 elements, b2 has 0." << endl;
}

void ex12_2(){
    cout << "-----ex12.2-----" << endl;
}

void ex12_3(){
    cout << "-----ex12.3-----" << endl;
    // https://isocpp.org/wiki/faq/const-correctness#const-member-fns
    // http://www.douban.com/group/topic/61573279/
    cout << "refer to https://github.com/Mooophy/Cpp-Primer/tree/master/ch12 " << endl;
}

void ex12_4(){
    cout << "-----ex12.4-----" << endl;
    cout << "we don't need to check if i is greater than 0 in function check because\n";
    cout << "i is unsigned, any less than 0 input will convert to greater than 0." << endl;
}



int main(int argc, const char * argv[]) {
//    ex12_1();
//    ex12_2();
//    ex12_3();
//    ex12_4();
    
    
    return 0;
}
