#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
#include <iomanip>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef vector<pair<lli,lli> > vplli;

inline bool isPrime(lli n){
	if (n <= 1)  {
		return false;
	}
	if (n <= 3)  {
		return true;
	}

	if (n%2 == 0 || n%3 == 0) {
		return false;
	}
	
	for (int i=5; i*i<=n; i=i+6){
		if (n%i == 0 || n%(i+2) == 0){
			return false;
		}
	}

	return true;
}

inline bool isEven(lli x){
	if(x&1) return false;
	else return true;
}

int main(){
	int t;
	cin>>t;
	while(t--){
		//cout<<"raghav"<<endl;
		lli n,d,k=0,sum=0,count=0,temp=0,temp2,x=0,temp3,ans=0,temp4=0;
		cin>>n>>d;
		lli arr[n];
		for (int i=0;i<n;i++)
			cin>>arr[i];

		while(k<d){
			for (int i=k;i<n;i += d){
				sum += arr[i];
				count++;
			}
			/*cout<<"sum= "<<sum<<endl;
			cout<<"count= "<<count<<endl;*/
			if (sum%count != 0){
				temp = 1;
				//cout<<"raghav"<<endl;
				break;
			}
			else{
				temp3 = sum/count;
				//cout<<"temp3= "<<temp3<<endl;
				if (x == 0)
					temp2 = temp3;
				else{
					if (temp2 != temp3){
						temp = 1;
						break;
					}


				} 
				x++;
			}
			sum = 0;
			count = 0;
			k++;
		}
		if (temp == 1){
			//cout<<"raman"<<endl;
			cout<<-1<<endl;
			continue;
		}
		k = 0;
		//cout<<"temp3= "<<temp3<<endl;
		while(k<d){
			for (int i=k;i<n;i += d){
				//cout<<"arr[i]= "<<arr[i]<<endl;
				if (arr[i]<temp3){
					temp4 = temp3-arr[i];
					ans += temp4;
					//cout<<"ans= "<<ans<<endl;
					arr[i] += temp4;
					arr[i+d] -= temp4;
				}
				else if (arr[i]>temp3){
					temp4 = arr[i]-temp3;
					ans += temp4;
					arr[i] -= temp4;
					arr[i+d] += temp4;
				}
			}
			k++;
		}
		cout<<ans<<endl;
		/*for (int i=0;i<n;i++)
			cout<<"arr[i]= "<<arr[i]<<endl;*/

		
	}
}