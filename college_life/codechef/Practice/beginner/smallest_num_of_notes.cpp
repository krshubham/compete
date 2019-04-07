#include <iostream>
using namespace std;

int main(int argc, char const *argv[])
{
	int n,a,num;
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a;
		num = (int)(a/100) + (int)((a%100)/50) + (int)((a%100%50)/10) + (int)((a%100%50%10)/5) + (int)((a%100%50%10%5)/2) + (int)((a%100%50%10%5%2)/1);
		cout<<num<<endl;
	}
	return 0;
}
