//
//  BinaryItem.h
//  SinhDayNhiPhanDoDaiN
//
//  Created by ThinhLe on 3/19/18.
//  Copyright © 2018 ThinhLe. All rights reserved.
//

#ifndef BinaryItem_h
#define BinaryItem_h
#include <string>
using namespace std;

class BinaryItem
{
public:
    int* value;
    int length;
public:
    BinaryItem();
    BinaryItem(const BinaryItem&);
    BinaryItem(int length);
    ~BinaryItem();
    void print();
    BinaryItem& increase();
    bool isMaxValue();
    BinaryItem& setLength(int length);
    BinaryItem& setValue(string str);
};


#endif /* BinaryItem_h */
