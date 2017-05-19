#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	string s;
	lli ss,c=0,l=0,h;
	cin>>s;
	ss = s.size();
	h = ss-1;
	if(l==1){
		cout<<"YES"<<endl;
		return 0;
	}
	for (int i = l; i < ss/2; ++i,h--){
		if(s[i] != s[h]){
			c++;
		}
	}
	if(c == 1){
		cout<<"YES"<<endl;
	}
	else if(c==0 && ss%2!=0){
    	cout<<"YES"<<endl;
	}
	else{
		cout<<"NO"<<endl;
	}
	return 0;
}
