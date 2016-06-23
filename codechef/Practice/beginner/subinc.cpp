#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;
int main(){
	std::ios::sync_with_stdio(false);
	int t;
	int l;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int count=0;
		lli arr[n];
		for (int i = 0; i < n; ++i)
			cin>>arr[i];
		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if(arr[j]>=arr[i]){
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}
