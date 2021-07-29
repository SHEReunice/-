#include <iostream>
using namespace std;

int T;
int n,m;
int a[105];
int main()
{
	
	cin >> T;
	while(T--)
	{
	cin >> n >> m;
	int tmp = m;
	int ans = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] >= tmp)
		{
			tmp = m;
			ans++;
		}else
		{
			tmp -= a[i];
		}
	}
	ans++; 
	cout << ans << endl;	
	}
	 } 
