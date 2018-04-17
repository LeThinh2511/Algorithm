//
//  Combination.h
//  ToHopChapKCuaN
//
//  Created by ThinhLe on 3/19/18.
//  Copyright © 2018 ThinhLe. All rights reserved.
//

#ifndef Combination_h
#define Combination_h

class Combination
{
public:
    int* value;
    int n;
    int k;
public:
    Combination();
    Combination(int k, int n);
    Combination(const Combination&);
    ~Combination();
    Combination& nextGeneration();
    void listAllCombination(int observer = 0);
    bool isMaxItem();
    void print();
};

#endif /* Combination_h */
