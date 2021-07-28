//
//  main.cpp
//  1002 A+B for Polynomials
//
//  Created by Eunice on 2021/7/23.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


float c[1005],d[1005],ans[1005];
bool a[1005];

int main(int argc, const char * argv[]) {
    int k1,k2,k3=0;
    int x;
    float y;
    int maxx = 0;
    memset(a,false,sizeof(a));
    memset(c,0.0,sizeof(c));
    memset(d,0.0,sizeof(d));
    memset(ans,0.0,sizeof(ans));
    cin >> k1;
    while(k1--){
        cin >> x >> y;
        maxx = max(maxx, x);
        a[x] = true;
        c[x] = y;
    }
    //cout << "hello" << endl;
    cin >> k2;
    while(k2--){
        cin >> x >> y;
        maxx = max(maxx, x);
        a[x] = true;
        d[x] = y;
    }
    for(int i = 0; i <= maxx; i++){
        if(!a[i]) continue;
        k3++;
        ans[i] = c[i] + d[i];
        if(ans[i] == 0.0){
            a[i] = false;
            k3--;
        }
    }
    cout << k3;
    for(int i = maxx; i >= 0; i--){
        if(!a[i]) continue;
        printf(" %d %.1f",i,ans[i]);
    }
    return 0;
}
