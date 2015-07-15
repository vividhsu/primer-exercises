//
//  Quote.cpp
//  chapter15
//
//  Created by vividhsu on 7/12/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include "Quote.h"


void Quote::debug() const {
    std::cout << "bookNo: " << isbn() << ", price: " << price << "." << std::endl;
}

/**

double Bulk_quote::net_price(size_t n) const{
    if (n >= min_qty) {
        return n * (1 - discount) * price;
    }
    else
        return n * price;
}

void Bulk_quote::debug() const {
    std::cout << "bookNo: " << isbn() << ", price: " << price << ", min_qty: " << min_qty << ", discount: " << discount << "." << std::endl;
}

double Limit_Quote::net_price(size_t n) const{
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
*/ 

double print_total (ostream &os, const Quote &item, size_t n) {
    double ret = item.net_price(n);
    os << "ISBN: " << item.isbn() << " # sold: " << n << " total due: " << ret << endl;
    return ret;
}
