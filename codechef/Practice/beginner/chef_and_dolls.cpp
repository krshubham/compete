#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int t,n;
	cin>>t;
	while(t--){
		cin>>n;
		vector<int> v(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>v[i];
		}
		sort(v.begin(),v.end());
		for (int i = 0; i <=n; ++i)
		{
			if(v[i]==v[i+1]){
				i++;
			}
			else{
				cout<<v[i]<<endl;
				break;
			}
		}
	}
	return 0;
}
