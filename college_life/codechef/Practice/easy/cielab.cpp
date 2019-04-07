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
	if(str[0]!= '1'){
		str[0] = (int)str[0] - 1;
		cout<<str<<endl;	
	}
	else if(str[0] == '1'){
		str[0] = '9';
		cout<<str<<endl;
	}
	return 0;
}
