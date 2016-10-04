#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	int t,n,ec=0;
	cin>>t;
	n = t;
	for(int i=0;i<t;i++){
		int a;
		cin>>a;
		if(a%2==0)
			ec++;
	}
	if(ec > (n - ec)){
		cout<<"READY FOR THE BATTLE"<<endl;
	}
	else{
		cout<<"NOT READY"<<endl;
	}
	return 0;
}
