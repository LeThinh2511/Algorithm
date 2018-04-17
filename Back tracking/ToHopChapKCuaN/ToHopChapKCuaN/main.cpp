//
//  main.cpp
//  ToHopChapKCuaN
//
//  Created by ThinhLe on 4/17/18.
//  Copyright © 2018 ThinhLe. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Combination.h"
using namespace std;

void getInput(int&, int&);

int main()
{
    int n = 0;
    int k = 0;
    try
    {
        getInput(n, k);
    }
    catch (exception)
    {
        cout << "Cannot open file!" << endl;
        return EXIT_FAILURE;
    }
    Combination item = Combination(k, n);
    item.listAllCombination();
    return 0;
}

void getInput(int& n, int& k)
{
    ifstream input = ifstream("input.txt");
    if (input.is_open())
    {
        cout << "Open file successfully" << endl;
    }
    else
    {
        throw exception();
    }
    input >> k;
    input >> n;
    input.close();
}
