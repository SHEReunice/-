#include<iostream>
#include<stdio.h>
#include<algorithm>
#include <string.h>
int s[200005];

using namespace std;
int main(){
	int T;
	cin >> T;
	int n;
	while(T>0){
		cin >> n;
		int a[n] = {0};
		memset(s,0,(n+1)*4); 
		int flag = -1;
		for(int i = 0; i < n; i++){
			cin >> a[i];
			s[a[i]]++;
		}
		for(int i = 0; i < n; i++){
			if(s[a[i]] == 1){
				if(flag == -1 || a[flag] > a[i])
					flag = i;
			}
		}
		
		if(flag != -1){
			cout << flag+1 << endl;
		}else{
			cout << -1 << endl;
		}
		T--;
	}
	
	return 0;
}
