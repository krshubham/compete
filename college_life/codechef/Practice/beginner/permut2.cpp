#include <bits/stdc++.h>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	while(n){
		int count = 0;
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		for (int i = 0; i < n; ++i)
		{
			
			if((arr[i] != i + 1) && (arr[arr[i]-1] != i + 1)){
				cout<<"not ambiguous"<<endl;
				break;
			}
			count++;
		}
		if(count==n){
			cout<<"ambiguous"<<endl;
		}			
		cin>>n;
	}
	return 0;
}
