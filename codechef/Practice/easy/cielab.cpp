#include <iostream>
#include <sstream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
	int a,b;
	cin>>a>>b;
	int s = a-b;
	stringstream ss;
	ss << s;
	string str = ss.str();
	str[str.length()/2] = str[str.length() - 1];
	cout<<str<<endl;
	return 0;
}
