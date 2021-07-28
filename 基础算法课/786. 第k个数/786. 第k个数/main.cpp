//
//  main.cpp
//  786. 第k个数
//
//  Created by Eunice on 2021/7/25.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>

using namespace std;


int n,k;
int q[100005];

void quick_sort(int q[], int l , int r);

int main(int argc, const char * argv[]) {
    scanf("%d %d",&n,&k);
    for(int i = 0; i < n; i++)
    {
        scanf("%d",&q[i]);
    }
    quick_sort(q,0,n-1);
    printf("%d",q[k-1]);
    return 0;
}

void quick_sort(int q[], int l, int r)
{
    if(l >= r) return;
    int mid = q[(l+r)/2],i = l-1, j = r+1;
    while(i < j)
    {
        do i++; while(q[i] < mid);
        do j--; while(q[j] > mid);
        if(i < j) swap(q[i], q[j]);
    }
    quick_sort(q, l, j);
    quick_sort(q, j+1, r);
}

