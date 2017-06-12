#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,a,b,c,d,e,f;
	cin>>t;
	string s;
	while(t--){
		cin>>s;
		b=0,c=0;
		a = s.size();
		for (int i = 0; i < a; ++i){
			if(s[i] == 's') b++;
			else c++;
		}
		if(a >=2 ){
			for (int i = a-1; i >= 0; i--){
				if(i == a-1){
					if(s[i-1] == 's' && s[i] == 'm'){
						b--;
					}
				}
				else{
					if((s[i] == 'm' && s[i-1] == 's') || (s[i] == 'm' && s[i+1] == 's')){
						b--;
					}
				}
			}
		}
		else{
			if(s[0] == 's'){
				cout<<"snakes"<<endl;
				continue;
			}
			else{
				cout<<"mongooses"<<endl;
				continue;
			}
		}
		if(b>c){
			cout<<"snakes"<<endl;
		}
		else if(b == c){
			cout<<"tie"<<endl;
		}
		else{
			cout<<"mongooses"<<endl;
		}

	}
	return 0;
}
