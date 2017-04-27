#include <iostream>
#include <vector>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	ulli t,a,b,c=0,sum=0,bc=0;
	cin>>t;
	while(t--){
		string s;
		cin>>a>>b;
		cin>>s;
		vector<char> v;
		for (int i = 0; i < s.size(); ++i){
			cout<<"s["<<i<<"]"<<" = "<<s[i]<<endl;
			if(s[i] == 'a')
				c++;
			else if(s[i] == 'b'){
				sum += c*bc;
			}
		}
	}
	return 0;
}
