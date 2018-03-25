//
//  main.cpp
//  HoanVi
//
//  Created by ThinhLe on 3/20/18.
//  Copyright © 2018 ThinhLe. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Permutation.h"
using namespace std;

int getInputFromFile();

int main()
{
    int numOfElement = 0;
    int count = 1;
    try
    {
        numOfElement = getInputFromFile();
    }
    catch (exception)
    {
        return 1;
    }
    
    Permutation item = Permutation(numOfElement);
    while (!item.isMaxItem())
    {
        item.print();
        cout << endl;
        count++;
        item.nextGeneration();
    }
    item.print();
    cout << endl;
    cout << "Number of item: " << count << endl;
    
    
    return 0;
}

int getInputFromFile()
{
    int value = 0;
    ifstream input = ifstream("input.txt");
    if (input.is_open())
    {
        input >> value;
    }
    else
    {
        throw exception();
    }
    return value;
}
