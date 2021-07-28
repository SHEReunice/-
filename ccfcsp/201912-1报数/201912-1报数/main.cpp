//
//  main.cpp
//  201912-1报数
//
//  Created by Eunice on 2021/7/19.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int n;
    cin >> n;
    int ans[4]={0};
    for(int i = 1; i <= n; i++){
        if((i%7) == 0 || (i%10)==7 || (i/10) == 7 || (i%100/10) == 7 || (i/100)==7){
            n++;
            if(i%4!=0){
              ans[i%4-1]++;
            }else{
                ans[3]++;
            }
            
        }
    }
    for(int i = 0; i < 4; i++){
        cout << ans[i] << endl;
    }
    
    
    
    
    return 0;
}
