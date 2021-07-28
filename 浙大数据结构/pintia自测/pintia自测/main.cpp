

#include <iostream>
#include <cstring>
#include <algorithm>
#include <math.h>
using namespace std;

int n;
int a[105],b[105],p[105];

int main(int argc, const char * argv[]) {
    /*
    int n;
    int max;
    int cnt;
    char r;
    cin >> n >> r;
    max = sqrt((n+1)*2)-1;
    
    
    for(int i = (max+1)/2; i > 0; i--){
        for(int j = 0; j < (max+1)/2-i; j++){
            cout << " ";
        }
        for(int k = 0; k < 2*i - 1; k++){
            cout << r;
            cnt++;
        }
       
        cout << endl;
    }
    for(int i = 2; i <= (max+1)/2; i++){
        for(int j = 0; j <(max+1)/2 - i; j++){
            cout << " ";
        }
        for(int k = 0; k < 2*i - 1; k++){
            cout << r;
            cnt++;
            
        }
        
        cout << endl;
    }
    cout << n-cnt;
    */
    /*
    int sum = 0;
    int cnt = 0;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    for(int i = 0; i < n; i++){
        cin >> b[i];
        if(a[i] == b[i]){
            p[i] = 1;
        }else if(a[i] < b[i]){
            p[i] = 1;
            sum++;
        }else{
            cnt++;
        }
    }
    if(cnt == 0){
        cout << -1;
    }else{
        cout << sum/cnt + 1;
    }
    */
    
    
    return 0;
}


