#include <iostream>
#include <iomanip>
using namespace std;

int main(int argc, char const *argv[]){
	int a;
	double b;
	cin>>a>>b;
	if(a%5!=0 || a+0.50>b ){
		cout<<fixed<<setprecision(2)<<b<<endl;
		return 0;
	}
	cout<<fixed<<setprecision(2)<<b-a-0.50<<endl;	
	return 0;
}
