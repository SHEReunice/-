//
//  main.cpp
//  3790. 录入单词
//
//  Created by Eunice on 2021/8/5.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
using namespace std;

int main(int argc, const char * argv[]) {
    int n, c,t[100005],ans=0;
    cin >> n >> c;
    for(int i = 1; i <= n ;i++)
    {
        cin >> t[i];
        if((t[i] - t[i-1]) <= c)
            ans++;
        else
            ans = 1;
    }
    cout << ans;
    return 0;
}
