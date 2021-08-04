//
//  main.cpp
//  795.前缀和
//
//  Created by Eunice on 2021/8/4.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
using namespace std;

const int N = 100005;
int q[N];
long long s[N];

int main(int argc, const char * argv[]) {
    int n,m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
          cin >> q[i];
          s[i] = s[i-1] + q[i];
     }
    while(m--)
    {
        int l,r;
        cin >> l >> r;
        cout << s[r] - s[l-1] << endl;
    }
      
    return 0;
}
