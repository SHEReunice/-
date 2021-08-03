//
//  main.cpp
//  高精度除法模板
//
//  Created by Eunice on 2021/7/29.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<int> div(vector<int> &A, int b, int &r)
//r是引用
{
    r = 0;
    vector<int> C;  //商
    for(int i = A.size() - 1; i >= 0; i--)
    {
        r = r * 10 + A[i];
        C.push_back(r/b);
        r %= b;
    }
    reverse(C.begin(), C.end());  //因为除法是从最高位开始，C是从高位往低位存的
    while(C.size() > 1 && C.back() == 0) C.pop_back();  //去掉前导0
    return C;
}

int main(int argc, const char * argv[]) {
    string  a;
    int b;
    
    cin >> a >> b;
    vector<int> A;
    for(int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');
    
    int r;
    vector<int> C = div(A, b, r);
    
    for(int i = C.size() - 1; i >= 0; i--)
    {
        printf("%d", C[i]);
    }
    cout << endl << r << endl;
    
    return 0;
}
