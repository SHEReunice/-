//
//  main.cpp
//  789.数的范围
//
//  Created by Eunice on 2021/7/27.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>

using namespace std;

int n,q,k;
int a[100005];

int main(int argc, const char * argv[]) {
    cin >> n >> q;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    while(q--)
    {
        cin >> k;
        int l = -1, r = -1,i,j;
        for(i = 0; i < n; i++)
        {
            if(a[i] == k)
            {
                l = i;
                break;
            }
        }
        for(j = i; j < n;j++)
        {
            if(a[j] == k)
            {
                r = j;
            }
        }
        cout << l << " " << r << endl;
    }
    return 0;
}
