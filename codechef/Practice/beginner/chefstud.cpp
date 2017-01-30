#include <iostream>
#include <string>
using namespace std;

typedef long long int lli;
typedef long long ll;

int main(int argc, char const *argv[])
{
	std::ios_base::sync_with_stdio(false);
	lli t;
	cin>>t;
	while(t--){
		lli count = 0;
		string s;
		cin>>s;
		for (int i = 0; i < s.size(); ++i){
			switch(s[i]){
				case '>':
					s[i] = '<';
					break;
				case '<':
					s[i] = '>';
					break;
			}
		}
		for (int i = 0; i < s.size()-1; ++i){
			if(s[i] == '>' && s[i+1] == '<'){
				count++;
			}
		}
		cout<<count<<endl;
	}
	return 0;
}