//
//  main.cpp
//  3774. 亮灯时长
//
//  Created by Eunice on 2021/7/23.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 100010;
int n,m;
int a[N],s1[N],s2[N]; //s1是s奇数区间和，s2是偶数区间和

int main(int argc, const char * argv[]) {
    /*
    int T;
    cin >> T;
    while(T--){
        cin >> n >> m;
        for(int i = 1; i <= n; i++) scanf("%d",&a[i]);
        a[++n] = m;
        s1[n] = s2[n] = 0;
        for(int i = n-1; i >= 0; i--){ //从后往前枚举，后缀和
            s1[n] = s1[i+1];
            s2[i] = s2[i+1];
            if(i % 2 == 0) s1[i] += a[i+1] - a[i];  //奇数区间
            else s2[i] += a[i+1] - a[i];  //偶数区间
        }
        
        int res = s1[0];
        for(int i = 0; i < n; i++){
            int t = a[i+1] - a[i];
            if(t == 1) continue;
            res = max(res, s1[0] - s1[i] + s2[i+1] + t - 1); //按的那部分最长是t-1
        }
        printf("%d\n",res);
    }
    */
    return 0;
}
