#include <iostream>
#include <cstdint>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef unsigned long long ull;


int main(){
	ios_base::sync_with_stdio(false);
	int64_t a,b,days=0;
	cin>>a>>b;
	if(a <=b ){
		cout<<a<<endl;
		return 0;
	}
	int64_t max = a;
	int64_t grains = a;
	while(1){
		days++;
		grains -= days;
		if(grains <= 0){
			break;
		}
		grains +=b;
		if(grains > max){
			grains = max;
		}
	}
	cout<<days<<endl;
	return 0;
}
