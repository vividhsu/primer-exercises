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
    Bulk_quote() = default;
    Bulk_quote(const string& book, double price, size_t qty, double disc): Disc_quote(book, price, qty, disc) {}
    double net_price(size_t n) const override;
};

#endif /* defined(__chapter15__Bulk_quote__) */
