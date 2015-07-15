//
//  main.cpp
//  chapter15
//
//  Created by vividhsu on 7/12/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include <iostream>

#include "Quote.h"
#include "Disc_quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"

using std::cout;
using std::endl;
using std::cin;


void ex15_01() {
    cout << "-----ex15.1-----" << endl;
    cout << "virtual member is member function that defines type-specific behavior, a derived class can override the function body from the base class." << endl;
}

void ex15_02() {
    cout << "-----ex15.2-----" << endl;
    cout << "protected member can be accessed by the members and friends of a derived class;\n";
    cout << "private can only be accessed by its own members." << endl;
}

void ex15_03() {
    cout << "-----ex15.3-----" << endl;
    
}

void ex15_04() {
    cout << "-----ex15.4-----" << endl;
    /**
      class Base {...};
     
      (a) class Derived: public Derived {...};
      WRONG: can't derived a class from itself. compiler wont know which members are from base.
     
      (b) class Derived: private Base {...};
      RIGHT.
     
      (c) class Derived: public Base;
      WRONG: derived class declaration contains the class name but does not include its derivation list.
    */
}

void ex15_05() {
    cout << "-----ex15.5-----" << endl;
}

void ex15_06() {
    cout << "-----ex15.6-----" << endl;
    Quote a("11-22-3333", 12.99);
    Bulk_quote b("22-33-444", 45.69, 50, 0.2);
    print_total(cout, a, 10);
    print_total(cout, b, 60);
    print_total(cout, b, 20);
}

void ex15_07() {
    cout << "-----ex15.7-----" << endl;
}

void ex15_08() {
    cout << "-----ex15.8-----" << endl;
    cout << "static type: it is the type with which a variable is declared or that an expression yield. known at the compile time. \n";
    cout << "dynamic type: it is the type of the object in memory that the variable or expression represents. known at the run time" << endl;
}

void ex15_09() {
    cout << "-----ex15.9-----" << endl;
    cout << "the static type of a pointer or reference to a base class may differ from its dynamic type" << endl;
}

void ex15_10() {
    cout << "-----ex15.10-----" << endl;
    cout << "ifstream and istringstream inherit from istream, derived-to-base conversion" << endl;
}

void ex15_11() {
    cout << "-----ex15.11-----" << endl;
    Quote a("11-22-3333", 12.99);
    Bulk_quote b("22-33-444", 45.69, 50, 0.2);
    a.debug();
    b.debug();
}

void ex15_12() {
    cout << "-----ex15.12-----" << endl;
    cout << "Yes, it is useful. declare a member function both override and final means this member function is derived from base class and also other derived class from this class can't override the function. " << endl;
}

/**

class base {
public:
    string name() { return basename; }
    virtual void print(ostream &os) { os << basename; }
private:
    string basename;
};

class derived: public base {
public:
    void print(ostream &os) { base::print(os); os << " " << i; }
private:
    int i;
};

base bobj;
derived dobj;

base *bp1 = &bobj;
base *bp2 = &dobj;
base &br1 = bobj;
base &br2 = dobj;

bobj.print();  // compile time
dobj.print();  // compile time
bp1 -> name(); // compile time
bp2 -> name(); // compile time
br1.print();   // run time
br2.print();   // run time
 
*/

void ex15_13() {
    cout << "-----ex15.13-----" << endl;

}

void ex15_14() {
    cout << "-----ex15.14-----" << endl;
    
    
}

void ex15_15() {
    cout << "-----ex15.15-----" << endl;
    Quote a("11-22-3333", 12.99);
    Bulk_quote b("11-22-333", 12.99, 50, 0.2);
    print_total(cout, a, 60);
    print_total(cout, b, 60);
    print_total(cout, b, 10);
}

void ex15_16() {
    cout << "-----ex15.16-----" << endl;
    Limit_quote c("11-22-333", 12.99, 50, 0.2, 100);
    print_total(cout, c, 110);
}

void ex15_17() {
    cout << "-----ex15.17-----" << endl;
    // Disc_quote d("11-22-333", 12.99, 50, 0.2);
}

int main(int argc, const char * argv[]) {
//    ex15_01();
//    ex15_02();
//    ex15_03();
//    ex15_04();
//    ex15_05();
//    ex15_06();
//    ex15_07();
//    ex15_08();
//    ex15_09();
//    ex15_10();
//    ex15_11();
//    ex15_12();
//    ex15_13();
//    ex15_14();
//    ex15_15();
//    ex15_16();
//    ex15_17();
    return 0;
}
