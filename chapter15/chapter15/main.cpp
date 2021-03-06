//
//  main.cpp
//  chapter15
//
//  Created by vividhsu on 7/12/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include <iostream>
#include <vector>
#include <memory>
#include <fstream>

#include "Quote.h"
#include "Disc_quote.h"
#include "Bulk_quote.h"
#include "Limit_quote.h"
#include "Basket.h"
#include "Query.h"
#include "WordQuery.h"
#include "NotQuery.h"
#include "AndQuery.h"
#include "OrQuery.h"
#include "TextQuery.h"
#include "QueryResult.h"

using std::cout;
using std::endl;
using std::cin;
using std::vector;
using std::shared_ptr;
using std::make_shared;
using std::ifstream;


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

/**
class Base {
public:
    void pub_mem();   // public member
protected:
    int prot_mem;     // protected member
private:
    char priv_mem;    // private member
};

class Pub_Derv: public Base {
public:
    void memfcn(Base &b) { b = *this; }             // legal
};

class Priv_Derv: private Base {
public:
    void memfcn(Base &b) { b = *this; }             // legal
};

class Prot_Derv: protected Base {
public:
    void memfcn(Base &b) { b = *this; }             // legal
};

class Derived_from_Public: public Pub_Derv {
public:
    void memfcn(Base &b) { b = *this; }             // legal
};
class Derived_from_Private: public Priv_Derv {
public:
    void memfcn(Base &b) { b = *this; }             // illegal
};
class Derived_from_Protected: public Prot_Derv {
public:
    void memfcn(Base &b) { b = *this; }             // legal
};

Base *p;
Pub_Derv d1;
Priv_Derv d2;
Prot_Derv d3;
Derived_from_Public dd1;
Derived_from_Private dd2;
Derived_from_Protected dd3;

p = &d1;     // legal
p = &d2;     // illegal
p = &d3;     // illegal
p = &dd1;    // legal
p = &dd2;    // illegal
p = &dd3;    // illegal
*/


void ex15_18() {
    cout << "-----ex15.18-----" << endl;
}

void ex15_19() {
    cout << "-----ex15.19-----" << endl;
}

void ex15_20() {
    cout << "-----ex15.20-----" << endl;
}

/**
class Base {
public:
    virtual int fcn();
};

class D1: public Base {
    int fcn();
    virtual void f2();
};

class D2: public D1 {
    int fcn();
    void f2();
};
*/

void ex15_23() {
    cout << "-----ex15.23-----" << endl;
}

void ex15_24() {
    cout << "-----ex15.24-----" << endl;
    cout << "A base class generally should define a virtual destructor. The destructor needs to be virtual to allow objects in the inheritance hierarchy to be dynamically allocated." << endl;
}

void ex15_25() {
    cout << "-----ex15.25-----" << endl;
    cout << "When we initialize the Bulk_quote, it called the default constructor of Disc_quote to initialize the members." << endl;
}

void ex15_26() {
    cout << "-----ex15.26-----" << endl;
    Quote a;
    std::cout << "----------" << std::endl;
    Quote b(a);
    std::cout << "----------" << std::endl;
    Quote c;
    c = a;
    std::cout << "----------" << std::endl;
    Quote d = std::move(a);
    std::cout << "----------" << std::endl;
    Bulk_quote ab("22-33", 3.99, 20, 0.2);
    std::cout << "----------" << std::endl;
    Bulk_quote bb(ab);
    std::cout << "----------" << std::endl;
    Bulk_quote cb;
    cb = ab;
    std::cout << "----------" << std::endl;
    Bulk_quote db = std::move(ab);
    std::cout << "----------" << std::endl;
}

void ex15_27() {
    cout << "-----ex15.27-----" << endl;
    Bulk_quote ab("22-33", 3.99, 20, 0.2);
    Bulk_quote bb(ab);
}

void ex15_28() {
    cout << "-----ex15.28-----" << endl;
    vector<Quote> basket;
    basket.push_back(Quote("11-222", 35.99));
    basket.push_back(Bulk_quote("11-222", 35.99, 20, 0.1));
    cout << basket[0].net_price(50) << endl;
    cout << basket[1].net_price(50) << endl;
}

void ex15_29() {
    cout << "-----ex15.29-----" << endl;
    vector<shared_ptr<Quote>> basket;
    basket.push_back(make_shared<Quote>("11-222", 35.99));
    basket.push_back(make_shared<Bulk_quote>("11-222", 35.99, 20, 0.1));
    cout << basket[0] -> net_price(50) << endl;
    cout << basket[1] -> net_price(50) << endl;
}

void ex15_30() {
    cout << "-----ex15.30-----" << endl;
    Basket bsk;
    bsk.add_item(Quote("11-222", 35.99));
    bsk.add_item(Bulk_quote("11-222", 35.99, 20, 0.1));
    double sum = bsk.total_receipt(cout);
}

void ex15_31() {
    cout << "-----ex15.31-----" << endl;
    /**
    (a) Query(s1) | Query(s2) & ~ Query(s3)
        OrQuery AndQuery NotQuery WordQuery
    (b) Query(s1) | (Query(s2) & ~ Query(s3))
        AndQuery NotQuery OrQuery WordQuery
    (c) (Query(s1) & (Query(s2)) | (Query(s3) & Query(s4)))
        AndQuery AndQuery OrQuery
    */
}

void ex15_34() {
    cout << "-----ex15.34-----" << endl;
    /**
    Query q = Query("fiery") & Query("bird") | Query("wind");
    (a)
     WordQuery::WordQuery(const string&): fiery
     Query::Query(const string&)
     WordQuery::WordQuery(const string&): bird
     Query::Query(const string&)
     BinaryQuery::BinaryQuery(const Query&, const Query&, string)
     AndQuery::AndQuery(const Query&, const Query&)
     Query::Query(shared_ptr<Query_base>)
     WordQuery::WordQuery(const string&): wind
     Query::Query(const string&)
     BinaryQuery::BinaryQuery(const Query&, const Query&, string)
     OrQuery::OrQuery(const Query&, const Query&)
     Query::Query(shared_ptr<Query_base>)
     (b)
     Query rep
     BinaryQuery rep
     Query rep
     BinaryQuery rep
     Query rep
     WordQuery rep
     Query rep
     WordQuery rep
     Query rep
     WordQuery rep
     (c)
     Query eval
     OrQuery eval
     Query eval
     AndQuery eval
     Query eval
     WordQuery eval
     Query eval
     WordQuery eval
     Query eval
     WordQuery eval
    */
}

void ex15_35() {
    cout << "-----ex15.35-----" << endl;

}

void ex15_36(const char* title) {
    cout << "-----ex15.36-----" << endl;
    Query q = Query("fiery") & Query("bird") | Query("wind");
    q.rep();
    ifstream is(title);
    TextQuery text(is);
    q.eval(text);
}

void ex15_38() {
    cout << "-----ex15.38-----" << endl;
    /**
    BinaryQuery a = Query("fiery") & Query("bird");
    illegal, BinaryQuery is an abstract class
    AndQuery b = Query("fiery") & Query("bird");
    legal
    OrQuery c = Query("fiery") & Query("bird");
    illegal, right side is an AndQuery, no conversion from AndQuery to OrQuery
    */
}

void ex15_39(const char* title) {
    cout << "-----ex15.39-----" << endl;
    ifstream is(title);
    TextQuery text(is);
    
    Query q = Query("fiery") & Query("bird") | Query("wind");
    QueryResult res = q.eval(text);
    
    print(cout, res);
}

void ex15_40() {
    cout << "-----ex15.40-----" << endl;
    cout << "still work." << endl;
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
//    ex15_18();
//    ex15_19();
//    ex15_20();
//    ex15_23();
//    ex15_24();
//    ex15_25();
//    ex15_26();
//    ex15_27();
//    ex15_28();
//    ex15_29();
//    ex15_30();
//    ex15_31();
//    ex15_34();
//    ex15_35();
//    ex15_36(argv[1]);
//    ex15_38();
//    ex15_39(argv[1]);
//    ex15_40();
    return 0;
}
