#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;

const int  N = 110;
int n,m;
char g[N][N];

void pl(int i, int j, int k){
	
	if(k==0) printf("%d %d %d %d %d %d\n",i,j,i+1,j,i,j+1);
	else if(k==1) printf("%d %d %d %d %d %d\n", i, j-1, i , j , i+1 ,j );
	else if(k==2) printf("%d %d %d %d %d %d\n", i-1 , j , i , j , i , j-1);
	else printf("%d %d %d %d %d %d\n", i-1 , j , i , j , i , j+1); 
}

int main(){
	int T;
	cin >> T;
	while(T--){
		cin >> n >> m;
		int res = 0;
		for(int i = 1; i <= n; i++){
			cin >> g[i] + 1;   //ָ��ƫ�ƣ�ֱ�Ӷ�һ��
			 for(int j = 1; j <= m; j++){
			 	if(g[i][j] == '1')
			 		res += 3;
			 }
		}
		cout << res << endl;
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= m; j++){
				if(g[i][j] == '1'){
					if(i < n && j < m) 
						pl(i,j,0),pl(i,j+1,1),pl(i+1,j,3);  //�����������Ͻ�ʱ��ͬʱ����������ұߵ� 
					else if(i == n && j  == m)
						pl(i,j,2),pl(i-1,j,1),pl(i,j-1,3);  //�������½ǣ������������� 
					else if(i == n)
						pl(i,j,3),pl(i-1,j,0),pl(i,j+1,2);  //���һ�У���Ϊ���½ǣ�����������ұ� 
					else if(j == m)
						pl(i,j,1),pl(i,j-1,0),pl(i+1,j,2); //���һ�У���Ϊ���Ͻ� 
					}
				}
			}
		}
		return 0;
	}

