//
//  Bulk_quote.h
//  chapter15
//
//  Created by vividhsu on 7/15/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter15__Bulk_quote__
#define __chapter15__Bulk_quote__

#include <iostream>
#include "Disc_quote.h"

class Bulk_quote: public Disc_quote {
public:
    using Disc_quote::Disc_quote;
    Bulk_quote() = default;
    //Bulk_quote(const string& book, double price, size_t qty, double disc): Disc_quote(book, price, qty, disc) {}

    // copy constructor
    Bulk_quote(const Bulk_quote& item): Disc_quote(item)
    { cout << "Bulk_quote: copy constructor" << endl; }
    // move constructor
    Bulk_quote(Bulk_quote&& item) noexcept:Disc_quote(std::move(item))
    {cout << "Bulk_quote: move constructor" << endl;}
    // copy assignment
    Bulk_quote& operator=(const Bulk_quote& rhs) {
        Disc_quote::operator=(rhs);
        cout << "Bulk_quote: copy assignment" << endl;
        return *this;
    }
    // move assignment
    Bulk_quote& operator=(Bulk_quote&& rhs) noexcept {
        if (this != &rhs) {
            Disc_quote::operator=(std::move(rhs));
        }
        cout << "Bulk_quote: move assignment" << endl;
        return *this;
    }

    
    double net_price(size_t n) const override;
};

#endif /* defined(__chapter15__Bulk_quote__) */
