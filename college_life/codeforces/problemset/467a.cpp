#include <iostream>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;



int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	lli a,b,n,count=0;
	cin>>n;
	for (int i = 0; i < n; ++i){
		cin>>a>>b;
		if(b-a>=2)
			count++;
	}
	cout<<count<<endl;
	return 0;
}
