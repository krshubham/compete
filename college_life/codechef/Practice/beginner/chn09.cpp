#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]){
	std::ios_base::sync_with_stdio(false);
	ll a;
	cin>>a;
	while(a--){
		string b;
		cin>>b;
		ll counta=0,countb=0;
		for(int i=0;i<b.size();i++){
			if(b[i] == 'a'){
				counta++;
			}
		}
		countb = b.size() - counta;
		counta > countb ? cout<<countb<<endl : cout<<counta<<endl; 
	}
	return 0;
}