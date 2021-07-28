//
//  main.cpp
//  三元数异或
//
//  Created by Eunice on 2021/7/22.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int main(int argc, const char * argv[]) {
    int T;
    cin >> T;
    while (T--) {
        int n;
        string x;
        cin >> n >> x;
        string a,b;
        bool flag = false;
        for(auto c: x)
        {
            if(c == '0') a += '0', b += '0';
            else if(c == '1')
            {
                if(flag) a += '0', b += '1';
                else a += '1', b += '0',flag = true;
            }
            else{
                if(flag) a += '0', b += '2';
                else  a += '1', b += '1';
            }
        }
        cout << a << endl << b << endl;
    }
    return 0;
}
