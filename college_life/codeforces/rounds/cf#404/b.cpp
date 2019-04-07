#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(){
	ios_base::sync_with_stdio(0);
	lli a,b,ta,tb;
	cin>>a;
	ta = a;
	std::vector<lli> pa,ca;
	while(a--){
		lli c,d;
		cin>>c>>d;
		ca.push_back(d);
	}
	cin>>b;
	tb = b;
	while(b--){
		lli c,d;
		cin>>c>>d;
		pa.push_back(c);
	}
	lli max = 0;
	for (int i = 0; i < tb; ++i){
		for (int j = 0; j < ta; ++j){
			 //cout<<"The values are: pa[i]: "<<pa[i]<<" and ca[j]: "<<ca[j]<<" and max is: "<<max<<endl;
			if(abs(pa[i] - ca[j]) >= max){
				max = pa[i] - ca[j];
			}
		}
	}
	cout<<abs(max)<<endl;
	return 0;
}
