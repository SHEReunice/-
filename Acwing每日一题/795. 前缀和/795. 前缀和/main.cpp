//
//  main.cpp
//  795. 前缀和
//
//  Created by Eunice on 2021/7/23.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int a[100005],s[100005];

int main(int argc, const char * argv[]) {
    int n;
    int m,ans;
    cin >> n >> m;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        if(i > 1) s[i] = s[i-1] + a[i];
        else s[i] = a[i];
    }
    int l,r;
    for(int i = 0; i < m; i++){
        cin >> l >> r;
        ans = s[r] - s[l] + a[l];
        cout << ans << endl;
    }
    return 0;
}
