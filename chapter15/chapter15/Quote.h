//
//  Quote.h
//  chapter15
//
//  Created by vividhsu on 7/12/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter15__Quote__
#define __chapter15__Quote__

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::endl;

class Quote {
public:
    Quote() = default;
    Quote(const string &book, double sales_price): bookNo(book), price(sales_price) {}
    string isbn() const {return bookNo; }
    virtual double net_price(size_t n) const { return n * price; }
    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price = 0.0;
};

double print_total (ostream &os, const Quote &item, size_t n);

#endif /* defined(__chapter15__Quote__) */
