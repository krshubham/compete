#include <iostream>
#include <cmath>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	lli t;
	cin>>t;
	while(t--){
		lli a;
		cin>>a;
		lli comp = ceil(a/8.0);
		lli max = 8*comp;
		lli min = max - 7;
		if(a == max){//16
			cout<<max-1<<"SL"<<endl;//15
		}
		else if(a == max - 1){//15
			cout<<max<<"SU"<<endl;//16
		}
		else if(a == max - 2){//14
			cout<<a - 3<<"UB"<<endl;//11
		}
		else if(a == max - 3){//13
			cout<<a - 3<<"MB"<<endl;//10
		}
		else if(a == max - 4){//12
			cout<<a - 3<<"LB"<<endl;//9
		}
		else if(a == max - 5){//11
			cout<<a + 3<<"UB"<<endl;
		}
		else if(a == max - 6){//10
			cout<<a + 3<<"MB"<<endl;
		}
		else if(a == max - 7){//9
			 cout<<a + 3<<"LB"<<endl;
		}
	}
	return 0;
}
