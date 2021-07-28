//
//  main.cpp
//  787.归并排序
//
//  Created by Eunice on 2021/7/26.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
using namespace std;

int n;
int q[100005], tmp[100005];

void merge_sort(int q[], int l, int r)
{
    if(l >= r) return;
    int mid = (l+r)/2;
    merge_sort(q, l, mid);
    merge_sort(q, mid+1, r);
    
    int i = l, j = mid+1;
    int k = 0;
    while(i <= mid && j <= r)
    {
        if(q[i] <= q[j])
            tmp[k++] = q[i++];
        else
            tmp[k++] = q[j++];
    }
    while( i <= mid) tmp[k++] = q[i++];
    while(j <= r) tmp[k++] = q[j++];
    
    for(i = l, j = 0; i <= r; j++,i++)
        q[i] = tmp[j];
    
}

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> q[i];
    
    merge_sort(q, 0, n-1);
    
    for(int i = 0; i < n; i++)
        cout << q[i] << " ";
    return 0;
}
