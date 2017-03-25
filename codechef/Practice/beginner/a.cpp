#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli a,b,c,d;
	cin>>a>>b>>c>>d;
	cout<<(a-c-b+d)/(d-b)<<endl;
	return 0;
}
