
#include <iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

struct node{
    int si;
    int dis;
}s[3];

bool cmp(node s1, node s2){
    return s1.dis < s2.dis;
}

int main(int argc, const char * argv[]) {
    int n,x,y;
    cin >> n >> x >> y;
    int sx[n],sy[n];
    for(int i = 0; i < 3; i++){
        cin >> sx[i] >> sy[i];
        s[i].si = i+1;
        s[i].dis = (sx[i] - x) * (sx[i] - x) + (sy[i] - y) *(sy[i] - y);
    }
    sort(s,s+3,cmp);
    
    if(n > 3){
        for(int i = 3; i < n; i++){
            cin >> sx[i] >> sy[i];
            int diss = (sx[i] - x) * (sx[i] - x) + (sy[i] - y) *(sy[i] - y);
            if(diss < s[0].dis){
            
                s[2].si = s[1].si;
                s[2].dis = s[1].dis;
                s[1].si = s[0].si;
                s[1].dis = s[0].dis;
                s[0].si = i+1;
                s[0].dis = diss;
                
            }else if (diss < s[1].dis){
                s[2].si = s[1].si;
                s[2].dis = s[1].dis;
                s[1].si = i+1;
                s[1].dis = diss;
            }else if (diss < s[2].dis){
                s[2].si = i+1;
                s[2].dis = diss;
            }
        }
    }
    
    for(int i = 0; i < 3; i++){
        cout << s[i].si << endl;
    }
    return 0;
}
