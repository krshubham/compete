#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--){
		int a,b,c;
		cin>>a>>b>>c;
		int v1[b],v2[c];
		vector<int> v(50);
		vector<int>::iterator iter;
		for (int i = 0; i < b; ++i)
		{	
			cin>>v1[i];
		}
		for (int i = 0; i < c; ++i)
		{
			cin>>v2[i];
		}
		set_intersection(v1,v1+b,v2,v2+c,v.begin());
		v.resize(iter-v.begin());
		for (iter=v.begin(); iter!=v.end(); ++iter)
			cout <<*iter<<endl; 
	}
	return 0;
}
