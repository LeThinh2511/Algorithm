//
//  Combination.cpp
//  ToHopChapKCuaN
//
//  Created by ThinhLe on 3/19/18.
//  Copyright © 2018 ThinhLe. All rights reserved.
//

#include <iostream>
#include "Combination.h"
using namespace std;


Combination::Combination()
{
    this->n = 0;
    this->k = 0;
    this->value = NULL;
}

Combination::Combination(const Combination& item)
{
    this->n = item.n;
    this->k = item.k;
    this->value = new int[k];
    for (int i = 0; i < k; i++)
    {
        this->value[i] = item.value[i];
    }
}

Combination::Combination(int k, int n)
{
    this->n = n;
    this->k = k;
    if (k != 0)
    {
        this->value = new int[k];
        for (int i = 0; i < k; i++)
        {
            this->value[i] = i;
        }
    }
    else
    {
        this->value = NULL;
    }
}

Combination& Combination::nextGeneration()
{
    int i = k - 1;
    while (value[i] == (n - (k - i)))
    {
        i--;
    }
    value[i] += 1;
    for (i += 1; i < k; i++)
    {
        value[i] = value[i - 1] + 1;
    }
    return *this;
}

Combination::~Combination()
{
    delete [] this->value;
}

bool Combination::isMaxItem()
{
    for (int i = 0; i < k; i++)
    {
        if (value[i] != (n - (k - i)))
        {
            return false;
        }
    }
    return true;
}

void Combination::print()
{
    if (value != NULL)
    {
        if (k > 0)
        {
            cout << "[" << value[0];
            for (int i = 1; i < k; i++)
            {
                cout << ", " << value[i];
            }
            cout << "]" << endl;
        }
    }
}

void Combination::listAllCombination(int observer)
{
    if (observer == this->k)
    {
        this->print();
    }
    else
    {
        if (observer == 0)
        {
            for (int i = 0; i < n; i++)
            {
                value[0] = i;
                listAllCombination(observer + 1);
            }
        }
        else
        {
            for (int i = value[observer - 1] + 1; i <= n - k + observer; i++)
            {
                this->value[observer] = i;
                this->listAllCombination(observer + 1);
            }
        }
    }
}












