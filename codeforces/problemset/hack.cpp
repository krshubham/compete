#include <bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	long long n,s,d,k,ans = 0;
	cin>>n;
	while(n--){
		cin>>s>>d;
		if(ans>s){
			k = (ans-s)/d+1;
			ans += s+k*d -ans;
		}
		else{
			ans += s-ans;
		}
	}
	cout<<ans;
}