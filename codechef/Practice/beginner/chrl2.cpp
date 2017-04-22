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
	lli state = 0,count=0;
	for(int i = 0; i<s.size(); i++){
		if(s[i] == 'C' && state == 0){
			state = 1;
		}
		else if(s[i] == 'H' && state == 1){
			state = 2;
		}
		else if(s[i] == 'E' && state == 2){
			state = 3;
		}
		else if(s[i] == 'F' && state == 3){
			state = 4;
		}
		if(state == 4){
			++count;
			state = 0;
		}
	}
	cout<<count<<endl;
	return 0;
}
