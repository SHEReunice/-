//
//  main.cpp
//  3776. 水果拼盘
//
//  Created by Eunice on 2021/7/25.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int T;


int main(int argc, const char * argv[]) {
    scanf("%d ",&T);
    while(T--)
    {
      int a,b,c,d,e,f;
        scanf("%d %d %d %d %d %d",&a,&b,&c,&d,&e,&f);
        int sum = 0;
        if(f > e)
        {
            int min2 = min(b,c);
            min2 = min(min2,d);
            if(min2 == d)
            { //香蕉都做拼盘2
                sum = d * f;
            }else
            {
                sum += min2 * f;
                d -= min2;
                int min1 = min(a,d);
                sum += min1 * e;
            }
        }else
        {
            int min1 = min(a,d);
            if(min1 == d)
            {
                sum += d * e;
            }else
            {
                sum += min1 * e;
                d -= min1;
                int min2 = min(b,c);
                min2 = min(min2, d);
                sum += min2 * f;
            }
        }
        printf("%d\n",sum);
    }
    
    return 0;
}
