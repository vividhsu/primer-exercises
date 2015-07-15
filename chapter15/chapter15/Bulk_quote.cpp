//
//  Bulk_quote.cpp
//  chapter15
//
//  Created by vividhsu on 7/15/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include "Bulk_quote.h"

double Bulk_quote::net_price(size_t n) const {
    if (n >= min_qty) {
        return n * (1 - discount) * price;
    }
    else
        return n * price;
}