//
//  BinaryItem.cpp
//  SinhDayNhiPhanDoDaiN
//
//  Created by ThinhLe on 3/19/18.
//  Copyright © 2018 ThinhLe. All rights reserved.
//

#include <iostream>
#include "BinaryItem.h"
using namespace std;


BinaryItem::BinaryItem()
{
    cout << "constructor 1";
    this->length = 0;
    this->value = NULL;
}

BinaryItem::BinaryItem(int length)
{
    cout << "constructor 2";
    this->length = length;
    this->value = new int[length];
    for (int i = 0; i < length; i++) {
        this->value[i] = 0;
    }
}

BinaryItem::~BinaryItem()
{
    delete [] this->value;
}

void BinaryItem::print()
{
    int count = this->length;
    for (int i = 0; i < count; i++)
    {
        cout << this->value[i];
    }
}

BinaryItem& BinaryItem::increase()
{
    int count = this->length;
    if (!this->isMaxValue())
    {
        for (int i = count - 1; i >= 0; i--)
        {
            if (this->value[i] == 1)
            {
                this->value[i] = 0;
            }
            else
            {
                this->value[i] = 1;
                break;
            }
        }
    }
    return *this;
}

bool BinaryItem::isMaxValue()
{
    for (int i = 0; i < this->length; i++)
    {
        if (this->value[i] == 0)
        {
            return false;
        }
    }
    return true;
}

