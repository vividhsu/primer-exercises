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
    virtual void debug() const;
    virtual ~Quote() = default;
private:
    string bookNo;
protected:
    double price = 0.0;
};

class Bulk_quote: public Quote {
public:
    Bulk_quote() = default;
    Bulk_quote(const string &book, double sales_price, size_t qty, double disc): Quote(book, sales_price), min_qty(qty), discount(disc) {}
    double net_price(size_t n);
    void debug() const override;
protected:
    size_t min_qty = 0;
    double discount = 0.0;
};

class Limit_Quote: public Bulk_quote {
public:
    Limit_Quote() = default;
    Limit_Quote(const string& book, double p, size_t qty, double disc, size_t limit): Bulk_quote(book, p, qty, disc), limit_qty(limit) {}
    double net_price(size_t n);
private:
    size_t limit_qty = 0;
};

double print_total (ostream &os, const Quote &item, size_t n);

#endif /* defined(__chapter15__Quote__) */
