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
void writeResultTo(ofstream& result, Combination& item);

int main()
{
    int k = 0;
    int n = 0;
    int count = 1;
    ofstream result = ofstream("result.txt");
    
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
        writeResultTo(result, item);
        item.nextGeneration();
        count++;
    }
    writeResultTo(result, item);
    cout << "Number of combinatiom: " << count << endl;
    
    result.close();
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

void writeResultTo(ofstream& result, Combination& item)
{
    result << "[" << item.value[0];
    for (int i = 1; i < item.k; i++)
    {
        result << ", " << item.value[i];
    }
    result << "]" << endl;
}
