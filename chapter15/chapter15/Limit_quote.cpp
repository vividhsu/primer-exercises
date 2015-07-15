//
//  Limit_quote.cpp
//  chapter15
//
//  Created by vividhsu on 7/15/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include "Limit_quote.h"

double Limit_quote::net_price(size_t n) const{
    if (n < min_qty) {
        return n * price;
    }
    else if (n > limit_qty) {
        return (n - limit_qty) * price + limit_qty * (1 - discount) * price;
    }
    else {
        return n * (1 - discount) * price;
    }
}
