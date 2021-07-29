#include<iostream>
#include <cstring>
#include <algorithm>
using namespace std;
int T;
int a[100005];

bool cmp(int a, int b){
	return (a<b);
}
int main(){
	cin >> T;
	while(T--){
		int n,x;
		cin >> n >> x; 
		int flag = 0;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			if(a[i] == x){
				flag = 1;
			}
		}
		if(flag == 1){
			cout << 1<< endl;
			continue;
		}
		sort(a,a+n,cmp);
		if(a[n-1] > x){
			cout << 2 << endl;
			continue;
		}else if(a[n-1] < x){
			if(x%a[n-1] == 0){
				cout << x/a[n-1] << endl; 
			}else {
				cout << x/a[n-1] + 1 << endl;
			}			
	}
}
return 0;
} 
