#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli a,b,c,d,count=0,i,j;
	cin>>a>>b>>c>>d;
	for (lli i = b; i < 99999999; i += a){
		if(!((i - d)%c)){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<-1<<endl;
	return 0;
}
