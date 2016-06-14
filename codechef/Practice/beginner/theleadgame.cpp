#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int r,a,b;
	int max=0;
	cin>>r;
	vector<int> p;
	for (int i = 0; i < r; ++i)
	{
		cin>>a>>b;
		if(a-b > b-a){
			p.push_back(1);
			p.push_back(a-b);
		} 
		else{
			p.push_back(2);
			p.push_back(b-a);
		}
	}
	int x = distance(p.begin(), max_element(p.begin(),p.end()));
    cout<<p[x-1]<<" "<<p[x]<<endl;
	return 0;
}