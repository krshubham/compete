#include <iostream>
#include <cmath>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	lli t;
	cin>>t;
	while(t--){
		lli a,n,m,temp,x;
		cin>>a>>n>>m;
		ulli nd = 0;
		temp = a,x=a;
		do{
			++nd; 
			temp /= 10;
		} while (temp);
		while(--n){
			a = a*pow(10,nd) + x;
		}
		if(m%5 == 0)
			cout<<temp<<endl;
		ulli rem = a%m;
		cout<<rem<<endl;
	}	
	return 0;
}