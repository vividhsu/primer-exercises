//
//  Basket.h
//  chapter15
//
//  Created by vividhsu on 7/26/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter15__Basket__
#define __chapter15__Basket__

#include <iostream>
#include <memory>
#include <set>

#include "Quote.h"

using std::shared_ptr;
using std::make_shared;
using std::multiset;
using std::ostream;
using std::endl;

class Basket {
public:
    void add_item(const Quote& sale);
    void add_item(Quote&& sale);
    double total_receipt(ostream &os) const;
private:
    static bool compare(const shared_ptr<Quote> &lhs, const shared_ptr<Quote> &rhs) {
        return lhs -> isbn() < rhs -> isbn();
    }
    multiset<shared_ptr<Quote>, decltype(compare)*> items{compare};
};

#endif /* defined(__chapter15__Basket__) */
