#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long long int lli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t;
	string s;
	cin>>t;
	while(t--){
		cin>>s;
		int len = s.size();
		lli ca=0,cb=0,cc=0,cd=0;
		for (int i=0;i<len;i++){
			if (s[i] == 'a')
				ca++;
			else if(s[i] == 'b')
				cb++;
			else if(s[i] == 'c')
				cc++;
			else if(s[i] == 'd')
				cd++;
		}
		lli arr[] = {ca,cb,cc,cd};
		if(ca != 0 && cb!= 0 && cc != 0 && cd != 0)
			cout<<(*max_element(arr,arr+4) + (ca*cb) + (cc*cd))%1000000007<<endl;
		else{
			cout<<((ca*cb) + (cc*cd))%1000000007<<endl;
		}
	}
	return 0;
}
