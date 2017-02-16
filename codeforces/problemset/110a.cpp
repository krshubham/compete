#include <iostream>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef double dbl;
typedef string str;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	str a;
	cin>>a;
	for (int i = 0; i < a.size(); ++i){
		cout<<a[i]<<endl;
	}

	return 0;
}