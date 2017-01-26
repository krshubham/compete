#include <iostream>
using namespace std;

typedef long long ll;


int main(int argc, char const *argv[]){
	ll a,b,c;
	scanf("%lld",&a);
	while(a--){
		ll sum=0;
		scanf("%lld %lld", &b,&c);
		for(ll i=b;i<=c;i++){
			ll revnum=0,remainder, temp;
			temp = i;
			while(temp!=0) {
				remainder = temp%10;
				revnum = revnum*10 + remainder;
				temp /= 10;
			}
			if (revnum == i){
				sum+=i;
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
