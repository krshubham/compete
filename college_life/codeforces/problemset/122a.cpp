#include <iostream>
using namespace std;

#define fin return 0 

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli a,b,c,d,n;
	cin>>n;
	lli arr[] = {4,7,47,447,74,774,44,77,444,777,474,747,744,477};
	for (int i = 0; i < 14; ++i){
		if(n%arr[i] == 0){
			cout<<"YES"<<endl;
			fin;
		}
	}
	cout<<"NO"<<endl;
	return 0;
}
