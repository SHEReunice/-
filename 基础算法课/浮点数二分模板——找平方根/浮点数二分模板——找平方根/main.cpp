//
//  main.cpp
//  浮点数二分模板——找平方根
//
//  Created by Eunice on 2021/7/26.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
using namespace std;


int main(int argc, const char * argv[]) {
    double x;
    cin >> x;
    double l = 0, r = x;
    while(r - l > 1e-6)  //保留六位小数，，比题意多两位
    {
        double mid = (l+r)/2;
        if(mid * mid >= x) r = mid;
        else l = mid;
    }
    
    //另一种写法
    
    /*
     for(int i = 0; i <100; i++)
     {
         double mid = (l+r)/2;
         if(mid * mid >= x) r = mid;
         else l = mid;
     }
     */
    printf("%lf\n", l);
    return 0;
}
