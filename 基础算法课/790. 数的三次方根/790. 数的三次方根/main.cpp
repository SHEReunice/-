//
//  main.cpp
//  790. 数的三次方根
//
//  Created by Eunice on 2021/8/3.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    double n;
    cin >> n;
    double l = -10000, r = 10000;
    while(r - l > 1e-8)
    {
        double mid = (l + r) / 2;
        if(mid * mid * mid >= n) r = mid;
        else l = mid;
    }
    printf("%lf\n", l);
    return 0;
}
