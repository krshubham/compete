#include <iostream>
#include <cmath>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	long double a;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>a;
		cout<<(int)sqrt(a)<<endl;
	}
	return 0;
}