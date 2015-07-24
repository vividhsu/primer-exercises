//
//  Limit_quote.h
//  chapter15
//
//  Created by vividhsu on 7/15/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter15__Limit_quote__
#define __chapter15__Limit_quote__

#include <iostream>
#include "Disc_quote.h"

class Limit_quote: public Disc_quote {
public:
    Limit_quote() = default;
    Limit_quote(const string& book, double p, size_t qty, double disc, size_t limit): Disc_quote(book, p, qty, disc), limit_qty(limit) {}
    
    // copy constructor
    Limit_quote(const Limit_quote& item): Disc_quote(item), limit_qty(item.limit_qty)
    { cout << "Limit_quote: copy constructor" << endl; }
    // move constructor
    Limit_quote(Limit_quote&& item) noexcept:Disc_quote(std::move(item)), limit_qty(std::move(item.limit_qty))
    {cout << "Limit_quote: move constructor" << endl;}
    // copy assignment
    Limit_quote& operator=(const Limit_quote& rhs) {
        Disc_quote::operator=(rhs);
        limit_qty = rhs.limit_qty;
        cout << "Limit_quote: copy assignment" << endl;
        return *this;
    }
    // move assignment
    Limit_quote& operator=(Limit_quote&& rhs) noexcept {
        if (this != &rhs) {
            Disc_quote::operator=(std::move(rhs));
            limit_qty = std::move(rhs.limit_qty);
        }
        cout << "Limit_quote: move assignment" << endl;
        return *this;
        }

    
    double net_price(size_t n) const override;
private:
    size_t limit_qty = 0;
};

#endif /* defined(__chapter15__Limit_quote__) */
