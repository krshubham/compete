#include <iostream>
#define endl "\n"
#include <map>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--){
		int n,m;
		int a;
		cin>>n>>m;
		bool arr[n];
		for(int i=0;i<m;i++){
			cin>>a;
			arr[a] = true;
		}	
		map<int,int> x;
		for (int i = 0; i < n; ++i)
		{
			if(arr[i] != 1){
				x[arr[i]] = i+1;
			}
		}
		
	}
	return 0;
}
