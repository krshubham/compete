#include <iostream>
#include <utility>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<int,int> pii;
typedef pair<lli,lli> plli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t;
	cin>>t;
	while(t--){
		lli n,p,mr;
		cin>>n;
		lli max = 0,index=0;
		plli arr[n];
		lli a[n],b[n];
		for(int i=0; i<n;i++){
			cin>>a[i];
		}
		for(int i=0; i<n; i++){
			cin>>b[i];
			p = b[i]*a[i];
			if(p > max){
				index = i;
				max = p;
				mr = b[i];
			}
			else if(p == max){
				if(b[i] > mr){
					mr = b[i];
					index = i;
				}
			}
		}
		cout<<++index<<endl;
	}	
	return 0;
}
