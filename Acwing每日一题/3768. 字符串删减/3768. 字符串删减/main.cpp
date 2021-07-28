//
//  main.cpp
//  3768. 字符串删减
//
//  Created by Eunice on 2021/7/21.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char ch[105];
int n;
int cnt=0;

int main(int argc, const char * argv[]) {
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> ch[i];
        if(i>=2 && ch[i] == 'x'){
            if(ch[i-1] == 'x' && ch[i-2] == 'x'){
                cnt++;
            }
        }
    }
    cout << cnt;
    return 0;
}
