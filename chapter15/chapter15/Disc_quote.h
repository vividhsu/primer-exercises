//
//  Disc_quote.h
//  chapter15
//
//  Created by vividhsu on 7/15/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter15__Disc_quote__
#define __chapter15__Disc_quote__

#include <iostream>
#include "Quote.h"

class Disc_quote: public Quote{
public:
    Disc_quote() = default;
    Disc_quote(const string& book, double price, size_t qty, double disc): Quote(book, price), min_qty(qty), discount(disc)
    {
        //cout << "Disc_quote: constructor" << endl;
    }
    // copy constructor
    Disc_quote(const Disc_quote& item): Quote(item), min_qty(item.min_qty), discount(item.discount)
    {
        //cout << "Disc_quote: copy constructor" << endl;
    }
    // move constructor
    Disc_quote(Disc_quote&& item) noexcept:Quote(std::move(item)), min_qty(std::move(item.min_qty)), discount(std::move(item.discount))
    {
        //cout << "Disc_quote: move constructor" << endl;
    }
    // copy assignment
    Disc_quote& operator=(const Disc_quote& rhs) {
        Quote::operator=(rhs);
        min_qty = rhs.min_qty;
        discount = rhs.discount;
        //cout << "Disc_quote: copy assignment" << endl;
        return *this;
    }
    // move assignment
    Disc_quote& operator=(Disc_quote&& rhs) noexcept {
        if (this != &rhs) {
            Quote::operator=(std::move(rhs));
            min_qty = std::move(rhs.min_qty);
            discount = std::move(rhs.discount);
        }
        //cout << "Disc_quote: move assignment" << endl;
        return *this;
    }
    
    double net_price(size_t n) const = 0;
    Disc_quote* clone() const & = 0;
    Disc_quote* clone() && = 0;
    
protected:
    size_t min_qty = 0;
    double discount = 0.0;
};

#endif /* defined(__chapter15__Disc_quote__) */
