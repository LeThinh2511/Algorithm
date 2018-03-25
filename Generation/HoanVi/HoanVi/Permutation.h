//
//  Permutation.h
//  HoanVi
//
//  Created by ThinhLe on 3/20/18.
//  Copyright © 2018 ThinhLe. All rights reserved.
//

#ifndef Permutation_h
#define Permutation_h

class Permutation
{
public:
    int numOfElement;
    int* value;
public:
    Permutation();
    Permutation(int numOfElement);
    ~Permutation();
    Permutation& nextGeneration();
    void print();
    Permutation& swap(int i, int j);
    bool isMaxItem();
};

#endif /* Permutation_h */
