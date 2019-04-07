#include <iostream>
using namespace std;

typedef long long ll;

int main(int argc, char const *argv[]){
	ll a;
	scanf("%lld",&a);
	while(a--){
		ll bs;
		scanf("%lld",&bs);
		if(bs < 1500){
			double finalsal = 0.1*bs + 0.9*bs + bs;
			cout<<finalsal<<endl;
		}
		else{
			double finalsal = 500 + 0.98*bs + bs;
			cout<<finalsal<<endl;
		}

	}
	return 0;
}