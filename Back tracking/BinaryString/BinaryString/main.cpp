//
//  main.cpp
//  BinaryString
//
//  Created by ThinhLe on 4/15/18.
//  Copyright © 2018 ThinhLe. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "BinaryItem.h"
using namespace std;

void getInput(int&);
void showResult(BinaryItem, int);

int main(int argc, const char * argv[]) {
    
    int length = 0;
    int observer = 0; // tracking the number of bit
    try
    {
        getInput(length);
    } catch (exception)
    {
        cout << "Cannot open file!" << endl;
        return EXIT_FAILURE;
    }
    BinaryItem item = BinaryItem(length);
    showResult(item, observer);
    return 0;
}

void getInput(int& length)
{
    ifstream input = ifstream("input.txt");
    if (input.is_open())
    {
        cout << "Open file successfully!" << endl;
        input >> length;
    }
    else
    {
        throw exception();
    }
}

void showResult(BinaryItem item, int observer)
{
    if (observer == item.length)
    {
        //call function to write to file
        item.print();
        cout << endl;
    }
    else
    {
        for (int i = 0; i < 2; i++)
        {
            item.value[observer] = i;
            showResult(item, observer + 1);
        }
    }
}

