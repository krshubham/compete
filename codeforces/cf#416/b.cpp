#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

#define end return 0

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);	
	lli a,b,c,d,e,f,n,m,t;
	cin>>n>>m;
	map<lli,lli> ma;
	lli arr[n];
	for (int i = 0; i < n; ++i){
		cin>>a;
		ma[i] = a;
	}
	for (int i = 0; i < m; ++i){
		cin>>b>>e>>f;
		for (int i = 0; i < n; ++i){
			arr[i] = ma[i];
		}
		sort(arr+(b-1),arr+e);
		if(arr[f-1] == ma[f-1]){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
	end;
}
