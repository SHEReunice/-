 #include <iostream>
 #include <cstring>
 #include <algorithm>
 using namespace std;
 
 int T;
int main(){
	cin >> T;
	while(T--){
		int a[15][15];
		int n,m;
		int sum = 0, min=1e8, cnt = 0;
		cin >> n >> m;
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> a[i][j];
				sum += abs(a[i][j]);
				if(a[i][j] < 0){
					cnt++;
				}
				if(abs(a[i][j]) < min){
						min = abs(a[i][j]);
					}			
			}
		}
		if(cnt % 2 == 0){
			cout << sum << endl;
		}else{
			cout << sum - 2*min << endl;
		}
	}
	return 0;
	
} 
