#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,a,num;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		vector<int> v;
		for(int j=0;j<a;j++){
			cin>>num;
			v.push_back(num);
			sort(v.begin(),v.end());
		}
		cout<<v[0]+v[1]<<endl;
	}
	return 0;
}