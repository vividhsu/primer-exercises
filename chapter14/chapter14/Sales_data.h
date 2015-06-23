//
//  Sales_data.h
//  chapter14
//
//  Created by vividhsu on 6/21/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter14__Sales_data__
#define __chapter14__Sales_data__

#include <iostream>
#include <string>

using std::string;
using std::ostream;
using std::istream;

class Sales_data {
public:
    friend ostream& operator<<(ostream &, const Sales_data&);
    friend istream& operator>>(istream &, Sales_data&);
    friend Sales_data operator+(const Sales_data&, const Sales_data&);
    // constructor
    Sales_data () = default;
    Sales_data (string &s): bookNo(s) {}
    
    //member functions
    string isbn() const { return bookNo; }
    Sales_data& operator+=(Sales_data&);
    
private:
    // members
    string bookNo;
    unsigned unit_sold = 0;
    double revenue = 0.0;
    
    double avg_price() const;
};

ostream& operator<<(ostream &, const Sales_data&);
istream& operator>>(istream &, Sales_data&);
Sales_data operator+(const Sales_data&, const Sales_data&);

#endif /* defined(__chapter14__Sales_data__) */
