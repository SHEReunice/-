//
//  main.cpp
//  3777.砖块
//
//  Created by Eunice on 2021/7/25.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int T;
int n;

bool check(string s, char c)
{
    int op[205];
    int j = 0;
    for(int i = 0; i < n-1; i++)
    {
        if(s[i] != c)
        {
            if(s[i] == 'W') s[i] = 'B';
            else s[i] = 'W';
            if(s[i+1] == 'W') s[i+1] = 'B';
            else s[i+1] = 'W';
            op[j++] = i+1;  //存一下操作的地方
        }
    }
    if(s[n-1] != s[0])  return false;
    if (j != 0)cout << j << endl;
    else cout << 0 << endl;
    for(int i = 0; i < j; i++)
    {
        cout << op[i] << " ";
    }
    if(j != 0) cout << endl;  //如果是不需要操作已经满足情况的话，上面已经输出过换行了
    return true;
}

int main(int argc, const char * argv[]) {
    cin >> T;
    while(T--){
        string s;
        cin >> n >> s;
        if(!check(s,'W') && !check(s,'B'))
        {
            cout << -1 << endl;
        }
    }
    return 0;
}
