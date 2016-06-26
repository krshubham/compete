#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int b;
		cin>>b;
		cout<<((b/2)*(b/2 - 1))/2<<endl;
	}
	return 0;
}
