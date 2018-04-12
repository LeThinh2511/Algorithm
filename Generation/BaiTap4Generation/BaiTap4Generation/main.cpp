//
//  main.cpp
//  BaiTap4Generation
//
//  Created by ThinhLe on 4/12/18.
//  Copyright © 2018 ThinhLe. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Combination.h"
#include <string>
using namespace std;

void getInput(string*&, int&, int&);
void print(string*, int, int);

int main(int argc, const char * argv[]) {
    string* people = NULL;
    int numOfPeopleInGroup = 0;
    int numOfPeople = 0;
    try
    {
        getInput(people, numOfPeopleInGroup, numOfPeople);
    }
    catch (exception)
    {
        return EXIT_FAILURE;
    }
    print(people, numOfPeopleInGroup, numOfPeople);
    delete [] people;
    return 0;
}

void getInput(string*& people, int& numOfPeopleInGroup, int& numOfPeople)
{
    ifstream input = ifstream("input.txt");
    if (input.is_open())
    {
        char temp[20];
        cout << "Open file successfully!" << endl;
        input >> numOfPeopleInGroup;
        input >> numOfPeople;
        if (numOfPeople > numOfPeopleInGroup || numOfPeople < 0 || numOfPeopleInGroup < 0)
        {
            cout << "So nguoi can chon phai be hon tong so nguoi!" << endl;
            throw exception();
        }
        people = new string[numOfPeopleInGroup];
        input.getline(temp, 20);
        for (int i = 0; i < numOfPeopleInGroup; i++)
        {
            input.getline(temp, 20);
            people[i] = temp;
        }
    }
    else
    {
        cout << "loi roi luom oi" << endl;
        throw exception();
    }
    input.close();
    
}

void print(string* people, int numOfPeopleInGroup, int numOfPeople)
{
    if (numOfPeople == 0)
    {
        cout << "nhap khac 0 di cau!" << endl;
        return;
    }
    Combination combination = Combination(numOfPeople, numOfPeopleInGroup);
    cout << "[";
    for (int i = 0; i < combination.k - 1; i++)
    {
        cout << people[combination.value[i]] << " ";
    }
    cout << people[combination.value[combination.k - 1]] << "]" << endl;
    while (!combination.isMaxItem())
    {
        cout << "[";
        for (int i = 0; i < combination.k - 1; i++)
        {
            cout << people[combination.value[i]] << " ";
        }
        cout << people[combination.value[combination.k - 1]] << "]" << endl;
        combination.nextGeneration();
    }
    
}
