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
    Disc_quote(const string& book, double price, size_t qty, double disc): Quote(book, price), min_qty(qty), discount(disc) {}
    double net_price(size_t n) const = 0;
    
protected:
    size_t min_qty = 0;
    double discount = 0.0;
};

#endif /* defined(__chapter15__Disc_quote__) */
