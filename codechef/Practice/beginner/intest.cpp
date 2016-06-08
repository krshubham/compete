#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);// the line helps to make cin faster a lot
	int n,k,a,count=0;
	cin>>n>>k;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		if(a%k==0){
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}
