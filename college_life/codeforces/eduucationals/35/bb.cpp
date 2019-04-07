#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	int n,a,b,M=1000;
	cin>>n>>a>>b;
	int mn1=M,mn2=M,mn=M,na;
	int mx=0;
	for(int i=1;i<n;i++){
		int j=n-i;
		mn1=a/i;
		mn2=b/j;
		mn=min(mn1,mn2);
		mx=max(mn,mx);
	}
	cout<<mx<<endl;
	return 0;
}

