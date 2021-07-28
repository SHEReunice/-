//
//  main.cpp
//  1001 A+B Format
//
//  Created by Eunice on 2021/7/23.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
char str[9];

int main(int argc, const char * argv[]) {
    int a,b;
    int sum;
    cin >> a >> b;
    sum = a+b;
    if(sum == 0){
        cout << 0;
        return 0;
    }
    if(sum < 0){
        cout << "-";
        sum = 0 - sum;
    }
    int i = 10,j = 0,flag = 0;
    while(sum > 0){
        int x = sum % i;
        str[j] = x + '0' ;
        ++flag;
        if(flag == 3 && sum/10 != 0){
            str[j+1] = ',';
            j += 2;
            flag = 0;
        }else{
           j++;
        }
        sum /= 10;
    }

    for(int i = j-1; i >= 0; i--){
        cout << str[i];
    }
    return 0;
}
