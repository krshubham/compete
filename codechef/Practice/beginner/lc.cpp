#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	int a,b;
	cout<<"Enter the two numbers separated by a space"<<endl;
	cin>>a>>b;
	int m = max(a,b);
	for(int i = m; i <=a*b; ++i){
		if(i%a == 0 && i%b == 0){
			cout<<"The LCM of the given numbers is: "<<i<<endl;
			break;
		}
	}	
	return 0;
}
