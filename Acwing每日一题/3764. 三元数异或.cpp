#include<iostream>
#include<string.h>
#include<algorithm>
#include <stdio.h>
using namespace std;
char a[50005],b[50005],x[50005];

int main(){
	int T;
	cin >> T;
	int n;
	while(T--){
		cin >> n;
		memset(x,'0',(n+1)); //这里乘4会报分段错误
		memset(a,'0',(n+1));
		memset(b,'0',(n+1));
		int flag = 0;
		string X;
		cin >> X;
		strcpy(x,X.c_str());
		a[0] = '1';
		b[0] = '1';
		for(int i = 0; i < n; i++){
			if(x[i] == '2'){
				a[i] = '1';
				b[i] = '1';
			}else if(x[i] == '0'){
				a[i] = '0';
				b[i] = '0';
			}else{
				a[i] = '1';
				b[i] = '0';
				flag = i;
				break;
			}
		}
		if(flag != 0){
		for(int i = flag+1; i < n; i++){
			if(x[i]=='2'){
					a[i] = '0';
					b[i] = '2';
			}else if(x[i] == '1'){
					a[i] = '0';
					b[i] = '1';
			}else{
				a[i] = '0';
				b[i] = '0';
			}
		}	
		}
		
	
	for(int i = 0; i < n; i++){
		cout << a[i];
	}
	cout << endl;
	for(int i = 0; i < n; i++){
		cout <<b[i];
	}
	cout << endl;
}
return 0;
	
} 
