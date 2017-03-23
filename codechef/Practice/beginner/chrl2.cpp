#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	string s;
	cin>>s;
	string sub = "CHEF";
	lli count = 0;
	int j = 0;
	for (int i=0; i<s.size()&&j<4; i++){
		cout<<s[i]<<" "<<ed
		if (sub[j] == s[i])
			j++;
		if(j == 4){
			count++;
			j = 0;
		}
	}
	cout<<count<<endl;
	return 0;
}
