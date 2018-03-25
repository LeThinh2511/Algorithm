//
//  main.cpp
//  ChinhHopLapChapKCuaN
//
//  Created by ThinhLe on 3/25/18.
//  Copyright © 2018 ThinhLe. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "ChinhHopLap.h"
using namespace std;

void getInputFromFile(int& k, int& n);


int main()
{
    int k = 0;
    int n = 0;
    int count = 1;
    try
    {
        getInputFromFile(k, n);
    }
    catch (exception)
    {
        return EXIT_FAILURE;
    }
    ChinhHopLap item = ChinhHopLap(k, n);
    while (!item.isMaxItem())
    {
        item.print();
        item.operator++();
        count++;
    }
    item.print();
    cout << endl << "Number of item: " << count << endl;
    return 0;
}

void getInputFromFile(int& k, int& n)
{
    ifstream input = ifstream("input.txt");
    if (input.is_open())
    {
        cout << "Opening file successfully!" << endl;
    }
    else
    {
        cout << "Cannot open file" << endl;
        throw exception();
    }
    
    input >> k;
    input >> n;
    input.close();
}
