#include<bits/stdc++.h>
using namespace std;
int trailzero(long long int n){
	long long int k=0,count=0,m=n;
	while(m>=5){
		m/=5;
		k++;
	}
	while(k>=1){
		count+=(n/(pow(5,k--)));
	}
	return count;
}
int main(){
	long int t;
	cin>>t;
	while(t--){
		long long int x,i=0;
		cin>>x;
		while(1){
			if(trailzero(i)>=x)
				break;
			else i+=5;
		}
		if(trailzero(i)>x){
			cout<<"0"<<endl;
			continue;
		}
		else{
			cout<<5<<endl;
			for(int z=0;z<5;z++){
				cout<<i++<<" ";
			}
		}
		cout<<endl;
	}
	return 0;
}