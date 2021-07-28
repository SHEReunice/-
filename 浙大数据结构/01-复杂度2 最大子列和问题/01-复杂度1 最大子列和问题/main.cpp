//
//  main.cpp
//  01-复杂度1 最大子列和问题
//
//  Created by Eunice on 2021/7/23.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int a[100005];
struct node{
    int first=0;
    int num=0;
}sum;

int main(int argc, const char * argv[]) {
    int k;
    cin >> k;
    long long int maxx = -1,firsti=0,lasti=0;
    bool note = false;
    for(int i = 0; i < k; i++)
    {
        cin >> a[i];
        if(a[i] >= 0){
            note = true;
        }
        sum.num += a[i];
        if(sum.num > maxx){
            firsti= sum.first;
            lasti = i;
            maxx = sum.num;
        }
        if(sum.num < 0){
            sum.num = 0;
            sum.first = i+1;
        }
    }
    if(note){
        cout << maxx << " " << a[firsti] << " " << a[lasti];
    }else{
        cout << 0 << " " << a[0] << " " << a[k-1];
    }
    
    return 0;
}
