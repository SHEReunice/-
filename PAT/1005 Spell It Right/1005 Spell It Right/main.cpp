//
//  main.cpp
//  1005 Spell It Right
//
//  Created by Eunice on 2021/7/23.
//  Copyright © 2021 Eunice. All rights reserved.
//

#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

char in[1005];

string getstr(int a)
{
    string str;
    switch (a) {
        case 0:
            str = "zero";
            break;
        case 1:
            str = "one";
            break;
        case 2:
            str = "two";
            break;
            case 3:
                str = "three";
                break;
            case 4:
                str = "four";
                break;
            case 5:
                str = "five";
                break;
            case 6:
                str = "six";
                break;
        case 7:
                str = "seven";
                break;
        case 8:
                str = "eight";
                break;
        case 9:
                str = "nine";
            break;
    
    }
            return str;
         
}

int main(int argc, const char * argv[]) {
    string line;
    getline(cin, line);
    int sum = 0, x;
    for(int i = 0; i < line.size(); i++){
        sum += line[i] - '0';
    }
    int i = 0;
    while(sum > 0)
    {
        in[i] = sum %10;
        sum /= 10;
        i++;
    }
    cout << getstr(in[i-1]);
    for(int j = i-2; j >=0; j--){
        string str = getstr(in[j]);
        cout << " " << str;
    }
    return 0;
}
