//
//  main.cpp
//  SinhDayNhiPhanDoDaiN
//
//  Created by ThinhLe on 3/19/18.
//  Copyright © 2018 ThinhLe. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "BinaryItem.h"
using namespace std;

int getInput();
void writeResult(BinaryItem& item);

int main()
{
    int length = 0;
    int count = 1;
    
    try
    {
        length = getInput();
    }
    catch (exception)
    {
        return EXIT_FAILURE;
    }
    
    BinaryItem item = BinaryItem(length);
    
    while (!item.isMaxValue())
    {
        writeResult(item);
        item.increase();
        count++;
    }
    writeResult(item);
    cout << "Number of item: " << count << endl;
    return 0;
}

int getInput()
{
    int n = 0;
    ifstream input = ifstream("input.txt");
    if (input.is_open())
    {
        cout << "Open file successfully!" << endl;
    }
    else
    {
        cout << "cannot open input file" << endl;
        throw exception();
    }
    input >> n;
    input.close();
    return n;
}

void writeResult(BinaryItem& item)
{
    ofstream result = ofstream("result.txt", ios::app);
    for (int i = 0; i < item.length; i++)
    {
        result << item.value[i];
    }
    result << "\n";
    result.close();
}

