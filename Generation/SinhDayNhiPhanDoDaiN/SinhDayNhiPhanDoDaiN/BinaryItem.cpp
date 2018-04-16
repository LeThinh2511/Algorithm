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
    this->length = 0;
    this->value = NULL;
    //cout << "constructor 1" << endl;
}

BinaryItem::BinaryItem(const BinaryItem& item)
{
    this->length = item.length;
    this->value = new int[this->length];
    for (int i = 0; i < this->length; i++)
    {
        this->value[i] = item.value[i];
    }
    //cout << "copy constructor" << endl;
}

BinaryItem::BinaryItem(int length)
{
    this->length = length;
    this->value = new int[length];
    for (int i = 0; i < length; i++)
    {
        this->value[i] = 0;
    }
    //cout << "constructor 2" << endl;
}

BinaryItem::~BinaryItem()
{
    //cout << "delete " << endl;
    delete [] this->value;
}

BinaryItem& BinaryItem::setLength(int length)
{
    delete this->value;
    this->length = length;
    this->value = new int[length];
    for (int i = 0; i < length; i++) {
        this->value[i] = 0;
    }
    return *this;
}

BinaryItem& BinaryItem::setValue(string str)
{
    long index = str.length() - 1;
    char character;
    for (int i = this->length - 1; i >= 0; i--)
    {
        if (index < 0)
        {
            this->value[i] = 0;
        }
        else
        {
            character = str.at(index);
            if (character == '1')
            {
                this->value[i] = 1;
            }
            else if (character == '0')
            {
                this->value[i] = 0;
            }
            else
            {
                this->value[i] = 0;
            }
            index--;
        }
    }
    return *this;
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

