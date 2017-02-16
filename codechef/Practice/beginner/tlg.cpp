#include <iostream>
#define MAX(a,b) (((a)>(b))?(a-b):(b-a))
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	lli t,temp;
	cin>>t;
	temp = t;
	lli arr[2*t];
	lli a,b,c=0;
	while(temp--){
		cin>>a>>b;
		if(a-b > 0){
			arr[c] = 1;
			arr[c+1] = a-b;
			c += 2;
		}
		else{
			arr[c] = 2;
			arr[c+1] = b-a;
			c+=2;
		}
	}
	lli max = 0,p;
	for (int i = 0; i < 2*t; ++i)
	{
		cout<<arr[i]<<" ";
	}
	for (int i = 1; i < 2*t; i+= 2)
	{
		if(arr[i] > max){
			max = arr[i];
			p = arr[i-1];
		}
	}
	cout<<p<<" "<<max<<endl;
	
	return 0;
}