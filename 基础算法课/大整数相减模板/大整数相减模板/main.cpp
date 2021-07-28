//
//  main.cpp
//  大整数相减模板
//
//  Created by Eunice on 2021/7/27.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//判断是否有A>=B
bool cmp(vector<int> &A, vector<int>&B)
{
    if(A.size() != B.size()) return A.size() > B.size(); //长度不一样，谁长d谁大
    for(int i = A.size() - 1; i >= 0; i--)
        if(A[i] != B[i])
            return A[i] > B[i];
    return true; //如果都相等，输出true
}

//C = A - B
//这里采用引用是为了更快处理，如果不加引用函数会把AB拷贝一遍
vector<int> sub(vector<int> &A, vector<int> &B)
{
    vector<int> C;
    int t = 0;
    for(int i = 0; i < A.size(); i++) //这里保证了A的size大于等于B
    {
        t = A[i] - t;
        if(i < B.size()) t -= B[i];
        C.push_back((t+10) % 10);  //（t+10)%10 = t%10 + 10%10 = t % 10;同余性质，所以不管它借不借位，余数是一样的
        if(t <  0) t = 1;
        else t = 0;
    }
    //这里A有多少位，C就有多少位，所以要把前面的0去掉，但是如果C只有一位就是0，就要留下
    while(C.size() > 1 && C.back() == 0) C.pop_back();
    return C;
}

int main(int argc, const char * argv[]) {
    string a, b;
    vector<int> A,B;
    
    cin >> a >> b; // a="123456"
    for(int i = a.size() - 1; i >= 0; i--)
        A.push_back(a[i] - '0');  // A = [6, 5, 4, 3, 2, 1]
    for(int i = b.size() - 1; i >= 0; i--)
        B.push_back(b[i] - '0');
    if(cmp(A,B))
    {
        auto C = sub(A,B);  //auto的意思是编译器会自己推断这是什么类型的
        
        for(int i = C.size()- 1; i >= 0; i--)
            printf("%d",C[i]);
    }else
    {
        auto C = sub(A,B);  //auto的意思是编译器会自己推断这是什么类型的
        printf("-");
        for(int i = C.size()- 1; i >= 0; i--)
            printf("%d",C[i]);
    }
    
    return 0;
}
