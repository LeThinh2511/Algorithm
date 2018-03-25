//
//  ChinhHopLap.cpp
//  ChinhHopLapChapKCuaN
//
//  Created by ThinhLe on 3/25/18.
//  Copyright © 2018 ThinhLe. All rights reserved.
//

#include <iostream>
#include "ChinhHopLap.h"
using namespace std;

ChinhHopLap::ChinhHopLap()
{
    k = 0;
    n = 0;
    item = NULL;
}

ChinhHopLap::ChinhHopLap(int k, int n)
{
    this->k = k;
    this->n = n;
    this->item = new int[k];
    for (int i = 0; i < k; i++)
    {
        item[i] = 0;
    }
}

ChinhHopLap::~ChinhHopLap()
{
    delete [] item;
}

bool ChinhHopLap::isMaxItem()
{
    for (int i = 0; i < k; i++)
    {
        if (item[i] != n - 1)
        {
            return false;
        }
    }
    return true;
}

void ChinhHopLap::print()
{
    if (item != NULL)
    {
        cout << "[";
        for (int i = 0; i < k - 1; i++)
        {
            cout << item[i] << ", ";
        }
        cout << item[k - 1] << "]";
    }
}

ChinhHopLap& ChinhHopLap::operator++()
{
    if (!this->isMaxItem())
    {
        int i = k - 1;
        if (item[i] < n - 1)
        {
            item[i]++;
        }
        else
        {
            do
            {
                item[i] = 0;
                i--;
            }
            while(item[i] == n - 1);
            item[i]++;
        }
    }
    return *this;
}



















