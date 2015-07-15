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
    double net_price(size_t n) const override;
private:
    size_t limit_qty = 0;
};

#endif /* defined(__chapter15__Limit_quote__) */
