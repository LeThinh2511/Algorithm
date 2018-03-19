//
//  main.cpp
//  ToHopChapKCuaN
//
//  Created by ThinhLe on 3/19/18.
//  Copyright © 2018 ThinhLe. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Combination.h"
using namespace std;

void getInput(int& k, int& n);

int main()
{
    int k = 0;
    int n = 0;
    
    try
    {
        getInput(k, n);
    } catch (exception)
    {
        return 1;
    }
    Combination item = Combination(k, n);
    
    while (!item.isMaxItem())
    {
        item.print();
        item.nextGeneration();
    }
    item.print();
    
    
    return 0;
}

void getInput(int& k, int& n)
{
    ifstream input = ifstream("input.txt");
    if (input.is_open())
    {
        cout << "Open file successfully!" << endl;
        input >> k;
        input >> n;
    }
    else
    {
        throw exception();
    }
    input.close();
}
