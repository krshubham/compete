#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,a,b;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a>>b;
		cout<<max(a,b)<<" "<<a+b<<endl;
	}
	return 0;
}