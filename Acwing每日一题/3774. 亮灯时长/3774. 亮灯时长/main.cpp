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

int a[100005],s1[100005],s2[100005];

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while(T--){
        int n,m;
        cin >> n >> m;
        a[0] = 0;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
            if(i % 2 != 0){
                s1[(i+1)/2] = a[i] - a[i-1];
                if(i > 1) s1[(i+1)/2] += s1[(i+1)/2-1];
            }else{
                s2[i/2] = a[i] - a[i-1];
                if(i > 2) s2[i/2] += s2[i/2-1];
            }
        }
        a[n+1] = m;
        if((n+1) % 2 != 0){
            s1[((n+1)+1)/2] = a[(n+1)] - a[n];
            if((n+1) > 1) s1[((n+1)+1)/2] += s1[((n+1)+1)/2-1];
        }else{
            s2[(n+1)/2] = a[(n+1)] - a[n];
            if((n+1) > 2) s2[(n+1)/2] += s2[(n+1)/2-1];
        }
        int res = s1[(n+2)/2];
        for(int i = 1; i <= n+1; i++){  //这里是a[i-1]到a[i]这个区间，所以是a[i-1]之前的奇数区间，a[i]之后的偶数区间
            int t;
            t = a[i] - a[i-1];
            res = max(res, s1[i/2] + s2[(n+1)/2]-s2[i/2] + t-1);  //i-1之前有（i-1+1)/2这么多个奇数区间，比如3之前有两个，0-1，2-3
            //a[i]之后有(n+1)/2-i/2这么多个，比如n=7，4之后有5-6一个偶数区间，4之前有4/2两个偶数区间，7之前有7/2三个偶数区间，所以两个相减就是一个区间
        }
        cout << res << endl;
    }
    return 0;
}
