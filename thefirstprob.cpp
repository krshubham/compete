#include <iostream>
using namespace std;

int main() {
	// your code goes here
	int a;
	while(1){
		cin>>a;
		if(a != 42){
			cout<<a<<endl;
		}
		else{
			return 0;
		}
	}
	return 0;
}