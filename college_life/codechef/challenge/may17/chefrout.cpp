#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,flag=0,z=0;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		// It accepts E at zeroth index :(
		// How can a person eat without cooking?
		//Compare ascii
		for(int i = 0; i < s.size(); i++) {
                int a = s[i];
                if(a >= z) {
                    flag = 1;
                    z = a;
                } else {
                    flag = 0;
                    break;
                }
            }
		if(flag == 1)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
		z = 0;
	}
	return 0;
}
