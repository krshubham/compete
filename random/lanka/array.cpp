#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
	int n;
	cout<<"Please enter the number of inputs"<<endl;
	cin>>n;
	int lanka[n];
	for (int i = 0; i < n; ++i){
		cin>>lanka[i];
	}
	for (int i = 0; i < n; ++i){
		cout<<lanka[i]<<"*"<<lanka[i]<<" = "<<lanka[i]*lanka[i]<<endl;
	}
	cout<<endl;
	return 0;
}
