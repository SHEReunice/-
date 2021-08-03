//
//  main.cpp
//  789.数的范围
//
//  Created by Eunice on 2021/7/27.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
using namespace std;

int n,m,q[100005];

void search1(int l, int r, int x)
{
    int i = l, j = r;
    if(l >= r) return ;
    while(l < r)
    {
        int mid = (l + r) / 2;
        if(q[mid] >= x)
            r = mid;
        else l = mid + 1;
    }
    if(q[l] != x)
    {
        cout << "-1 -1" << endl;
    }
    else
    {
        cout << l << " ";
        while(i < j)
        {
            int mid = (i + j + 1) / 2;
            if(q[mid] <= x) i = mid;
            else j = mid - 1;
        }
        cout << j << endl;
    }
}


int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> q[i];
    while(m--)
    {
        int x;
        cin >> x;
        search1(0, n-1, x);
    }
    
    
    return 0;
}
