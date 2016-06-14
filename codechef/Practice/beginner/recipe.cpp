#include <iostream>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	vector<int> p;
	while(t--){
		int a;
		cin>>a
		while(a--){
			int b;
			cin>>b;
			p.push_back(b);
		}
		for (int i = 0; i < p.size(); ++i)
		{
			cout<<p[i]<<endl;
		}
	}
	return 0;
}
