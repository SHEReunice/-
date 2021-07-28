//
//  main.cpp
//  3769. 移动石子
//
//  Created by Eunice on 2021/7/21.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T;

int main(int argc, const char * argv[]) {
    int n,d;
    cin >> T;
    while(T--){
        cin >> n >> d;
        int a[n];
        int flag = 0;
        for(int i = 0; i < n; i++){
            cin >> a[i];
            if(i > 0 && flag == 0 ){
                if(a[i] <= d/i){
                    a[0] += a[i];
                    d = d - a[i] * i;
                }else{
                    a[0] += d/i;
                    flag = 1;
                }
            }
        }
        cout << a[0] << endl;
    }
    return 0;
}
