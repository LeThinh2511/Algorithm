//
//  ChinhHopLap.h
//  ChinhHopLapChapKCuaN
//
//  Created by ThinhLe on 3/25/18.
//  Copyright © 2018 ThinhLe. All rights reserved.
//

#ifndef ChinhHopLap_h
#define ChinhHopLap_h
using namespace std;

class ChinhHopLap
{
public:
    int k;
    int n;
    int* item;
public:
    ChinhHopLap();
    ChinhHopLap(int k, int n);
    ~ChinhHopLap();
    void print();
    ChinhHopLap& nextGeneration();
    bool isMaxItem();
    ChinhHopLap& operator ++();
};

#endif /* ChinhHopLap_h */
