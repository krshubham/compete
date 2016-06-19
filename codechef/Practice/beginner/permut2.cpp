#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	while(n){
		int arr[n];
		for (int i = 0; i < n; ++i)
		{
			cin>>arr[i];
		}
		for (int i = 0; i < n; ++i)
		{
			if((arr[i] != i +1) && (arr[arr[i]-1] != arr[i])){
				break;
			}
			
		}
		cout<<"not ambiguous"<<endl;		
		cin>>n;
	}
	return 0;
}
