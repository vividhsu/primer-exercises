//
//  Sales_data.cpp
//  chapter14
//
//  Created by vividhsu on 6/21/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include "Sales_data.h"

double Sales_data::avg_price() const {
    if (unit_sold) {
        return revenue / unit_sold;
    }
    else
        return 0;
}

ostream& operator<<(ostream &os, const Sales_data &item) {
    os << item.isbn() << " " << item.unit_sold << " " << item.revenue << " " << item.avg_price();
    return os;
}