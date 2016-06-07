#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	long double b,ls;
	cin>>n;
	for (int i = 0; i < n; ++i)
	{
		cin>>b>>ls;
		cout<<sqrt(ls*ls - b*b)<<" "<<sqrt(ls*ls + b*b)<<endl;
	}
	return 0;
}