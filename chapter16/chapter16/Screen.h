//
//  Screen.h
//  chapter16
//
//  Created by vividhsu on 8/2/15.
//  Copyright (c) 2015 Vividhsu. All rights reserved.
//

#ifndef __chapter16__Screen__
#define __chapter16__Screen__

#include <iostream>
#include <string>

using namespace std;

template <unsigned H, unsigned W>
class Screen;

template <unsigned H, unsigned W>
ostream& operator<<(ostream& os, const Screen<H,W>&);

template <unsigned H, unsigned W>
istream& operator>>(istream& is, Screen<H,W>&);

template <unsigned H, unsigned W>
class Screen {
    friend ostream& operator<<<H,W>(ostream& os, const Screen<H,W>&);
    friend istream& operator>><H,W>(istream& is, Screen<H,W>&);
public:
    typedef string::size_type pos;
    // constructor
    Screen() = default;
    Screen(char c): contents(H*W, c) {}
    char get() const { return contents[cursor]; }
    char get(pos row, pos col) const {
        return contents[row * width + col];
    }
    
private:
    pos cursor = 0;
    pos height = H, width = W;
    string contents;
};

template <unsigned H, unsigned W>
ostream& operator<<(ostream& os, const Screen<H,W>& scr) {
    for (int i = 0; i < H; i++) {
        for (int j = 0; j < W; j++) {
            os << scr.get(i, j) << " ";
        }
        os << endl;
    }
    return os;
}

template <unsigned H, unsigned W>
istream& operator>>(istream& is, Screen<H,W>& scr) {
    char c;
    is >> c;
    Screen<H, W> temp(c);
    scr = temp;
    return is;
}

#endif /* defined(__chapter16__Screen__) */
