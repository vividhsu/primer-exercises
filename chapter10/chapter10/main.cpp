//
//  main.cpp
//  chapter10
//
//  Created by vividhsu on 5/14/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using std::count;

using std::vector;

using std::cin;
using std::cout;
using std::endl;

void ex10_1(){
    vector<int> a = {10, 45, 56, 78, 10, 34, 23, 10, 10};
    auto cnt = count(a.begin(), a.end(), 10);
    cout << cnt << endl;
}

int main(int argc, const char * argv[]) {
    ex10_1();
    return 0;
}
