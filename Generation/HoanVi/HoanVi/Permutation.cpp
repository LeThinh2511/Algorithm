//
//  Permutation.cpp
//  HoanVi
//
//  Created by ThinhLe on 3/20/18.
//  Copyright © 2018 ThinhLe. All rights reserved.
//

#include <iostream>
#include "Permutation.h"
using namespace std;

Permutation::Permutation()
{
    numOfElement = 0;
    value = NULL;
}

Permutation::Permutation(int numOfElement)
{
    this->numOfElement = numOfElement;
    if (numOfElement > 0)
    {
        this->value = new int[numOfElement];
        for (int i = 0; i < numOfElement; i++)
        {
            value[i] = i;
        }
    }
    else
    {
        this->value = NULL;
    }
}

Permutation::~Permutation()
{
    delete [] value;
}

Permutation& Permutation::nextGeneration()
{
    int i = numOfElement - 2;
    while (value[i] > value[i + 1])
    {
        i--;
    }
    
    int j = i + 1;
    int min = value[j];
    int index = j;
    while (j < numOfElement)
    {
        if (value[j] > value[i] && value[j] < min)
        {
            min = value[j];
            index = j;
        }
        j++;
    }
    
    this->swap(i, index);
    
    i += 1;
    j = numOfElement - 1;
    
    while (i < j)
    {
        this->swap(i, j);
        i++;
        j--;
    }
    
    return *this;
}

Permutation& Permutation::swap(int i, int j)
{
    int temp = 0;
    
    temp = value[i];
    value[i] = value[j];
    value[j] = temp;
    
    return *this;
}

void Permutation::print()
{
    if (value != NULL)
    {
        cout << "[";
        for (int i = 0; i < numOfElement - 1; i++)
        {
            cout << value[i] << ", ";
        }
        cout << value[numOfElement - 1] << "]";
    }
}

bool Permutation::isMaxItem()
{
    for (int i = numOfElement - 2; i >= 0; i--)
    {
        if (value[i] < value[i + 1])
        {
            return false;
        }
    }
    return true;
}













