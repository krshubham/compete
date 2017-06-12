#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli a,b,c,d,e,f,g,h,t;
	cin>>t;
	while(t--){
		cin>>a;
		c = 0,h=0;
		lli arr[a],br[a];
		d = (a/2)+1;
		for (int i = 1; i <= a; ++i){
			if(i == d){
				arr[i] = d;
			}
			if(i > d){
				arr[i] = arr[i-1] - 1; 
			}
			if(i < d){
				arr[i] = i;
			}
		}
		for (int i = 1; i <= a; ++i){
			cin>>br[i];
		}
		if(a%2 == 0){
			cout<<"no"<<endl;
			continue;
		}
		for (int i = 1; i <= a; ++i){
			// cout<<arr[i]<<" "<<br[i]<<endl;
			if(arr[i] != br[i]){
				cout<<"no"<<endl;
				h = 1;
				break;
			}
			else c++;
		}
		if(c == a && h == 0){
			cout<<"yes"<<endl;
		}
	}
	return 0;
}
