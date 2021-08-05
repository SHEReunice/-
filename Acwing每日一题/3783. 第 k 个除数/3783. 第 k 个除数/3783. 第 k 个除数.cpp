//
//  main.cpp
//  3783. 第 k 个除数
//
//  Created by Eunice on 2021/8/5.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    long long n, k, m=0,t=-1;
    cin >> n >> k;
    for(long long i = 1; i <= n; i++)
    {
        if(n%i==0)
        {
            m++;
            if(m == k)
            {
                t = i;
                break;
            }
        }
    }
    cout << t;
    return 0;
}
