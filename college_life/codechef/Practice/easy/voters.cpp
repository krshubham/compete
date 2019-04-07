#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	map<lli,int> m;
	map<lli,int>::iterator it;
	vector<lli> v;
	lli a,b,c,x,p;
	cin>>a>>b>>c;
	p = a+b+c;
	for (int i = 0; i < p; ++i){
		cin>>x;
		m[x]++;
	}
	for (it = m.begin(); it != m.end(); ++it){
		if(it->second >= 2){
			v.push_back(it->first);
		}	
	}
	sort(v.begin(),v.end());
	cout<<v.size()<<endl;
	for (int i = 0; i < v.size(); ++i){
		cout<<v[i]<<endl;
	}
	return 0;
}
