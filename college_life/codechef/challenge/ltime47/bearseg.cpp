#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(){
	int t;
	cin>>t;
	while(t--)
	{
		vector<ll>v1;
		vector<ll>v2;
		
		ll n,p,x,k=0,sum=0,b,z,m,count=0;
		//float b;
		cin>>n>>p;
		v1.reserve(n);
		v2.reserve(1000000);
		for (int i=0;i<n;i++){
			cin>>x;
			v1.push_back(x);
		}

		for (int i=0;i<n;i++){

			for (int j=i;j<n;j++){
				sum += v1[j];
				if (i == j){
					b = v1[j]%p;
					v2.push_back(b);
					k++;
				}
				else{
					z = sum % p;
					v2.push_back(z);
					k++;

				}


			}
			

			sum = 0;
		}


		sort(v2.begin(),v2.end());
		k = k-1;
		m = v2[k];
		//cout<<"m= "<<m<<endl;
		while(v2[k] == m)
		{
		//	cout<<"arr2[k]= "<<arr2[k]<<endl;
			count++;
			k--;			
		}
		cout<<m<<" "<<count<<endl;
		v1.resize(n);
		v2.resize(1000000);
	}
}


