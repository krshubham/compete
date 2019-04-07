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
#include <stack>
#include <climits>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828
#define stp(a,b) a.push(b)
#define all(a) a.begin(),a.end()
#define PI 3.1415926535897932384626433832795
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define crep(i,a,b) for( int i = a; i <= b; i++ )

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
	ios_base::sync_with_stdio(0);
	cin>>t;
	string s;
	while(t--){
		string str;
		cin>>str;
		lld k;
		lld x,y;
		cin>>x>>y;
		lld a,b,m=0,n=0,p,q;

		for(lld j=0;j<str.size();j++){
			if(str[j]=='a')
				m++;
			if(str[j]=='b')
				n++;
		}
		p=a=(lld)(m/x);
		q=b=(lld)(n/y);
		if(m-(p*x)!=0&&n-(q*y)!=0){
			if(p>q){
				for(lld j=0;j<p;j++){
					for(lld k=0;k<x;k++){
						cout<<'a';
					}
					if(q>0){
						for(lld k=0;k<y;k++){
							cout<<'b';
							q--;
						}
					}
					else if(q==0){
						for(lld k=0;k<n-(b*y);k++){
							cout<<'b';
							q--;
						}
					}
					else
						cout<<"*";
				}

				for(lld k=0;k<m-((a)*x);k++){
					cout<<'a';
				}
			}
			if(q>p){
				for(lld j=0;j<q;j++){
					for(lld k=0;k<y;k++){
						cout<<b;
					}
					if(p>=1){
						for(lld k=0;k<x;k++){
							cout<<'a';
							p--;
						}
					}
					else if(p==0){
						for(lld k=0;k<m-(a*x);k++){
							cout<<'a';
							p--;
						}
					}
					else
						cout<<"*";
				}
				for(lld k=0;k<n-(b*y);k++)
					cout<<'b';
			}
			if(q==p){
				for(lld j=0;j<q;j++){
					for(lld k=0;k<x;k++){
						cout<<'a';
					}
					for(lld k=0;k<y;k++){
						cout<<'b';
					}
				}
				for(lld k=0;k<m-(a*x);k++){
					cout<<'a';
				}
				for(lld k=0;k<n-(b*y);k++){
					cout<<'b';
				}
			}
			cout<<endl;
			continue;
		}
		if(m-(p*x)==0&&n-(q*y)==0){
			if(p>q){
				for(lld j=0;j<p-1;j++){
					for(lld k=0;k<x;k++){
						cout<<'a';
					}
					if(q>0){
						for(lld k=0;k<y;k++){
							cout<<'b';
							q--;
						}
					}
					else{
						cout<<"*";
					}
				}
				for(lld k=0;k<x;k++){
					cout<<'a';
				}
			}
			if(q>p){
				for(lld j=0;j<q-1;j++){
					for(lld k=0;k<y;k++){
						cout<<'b';
					}
					if(p>=1){
						for(lld k=0;k<x;k++){
							cout<<'a';
							p--;
						}
					}
					else{
						cout<<"*";
					}
				}
				for(lld k=0;k<y;k++){
					cout<<'b';	
				}
			}
			if(q==p){
				for(lld j=0;j<q;j++){
					for(lld k=0;k<x;k++){
						cout<<'a';
					}
					for(lld k=0;k<y;k++){
						cout<<'b';
					}
				}
			}
			cout<<endl;
			continue;
		}
		if((n-(q*y))!=0&&(m-(p*x))==0){
			q++;
			if(p>q){
				for(lld j=0;j<p-1;j++){
					for(lld k=0;k<x;k++){
						cout<<'a';
					}
					if(q>1){
						for(lld k=0;k<y;k++){
							cout<<'b';
							q--;
						}
					}
					else if(q==1){
						for(lld k=0;k<n-(b*y);k++){
							cout<<'b';
							q--;
						}
					}
					else{
						cout<<"*";
					}
				}
				for(lld k=0;k<x;k++){
					cout<<'a';
				}
			}
			if(q>p){
				for(lld j=0;j<q-1;j++){
					for(lld k=0;k<y;k++){
						cout<<'b';
					}
					if(p>0){
						for(lld k=0;k<x;k++){
							cout<<'a';
							p--;
						}
					}	
					else{
						cout<<"*";
					}	
				}
				for(lld k=0;k<n-(b*y);k++){
					cout<<'b';
				}
			}
			if(q==p){
				for(lld j=0;j<q-1;j++){
					for(lld k=0;k<x;k++){
						cout<<'a';
					}
					for(lld k=0;k<y;k++){
						cout<<'b';
					}
				}
				for(lld k=0;k<x;k++){
					cout<<'a';
				}
				for(lld k=0;k<n-(b*y);k++)
					cout<<'b';
			}
			cout<<endl;
			continue;
		}
		if(m-(p*x)!=0&&n-(q*y)==0){ 
			p++;
			if(p>q){
				for(lld j=0;j<p-1;j++){
					for(lld k=0;k<x;k++)
						cout<<'a';
					if(q>0){
						for(lld k=0;k<y;k++)
							cout<<'b';q--;
					}
					else
						cout<<"*";
				}
				for(lld k=0;k<m-(a*x);k++)
					cout<<'a';
			}
			if(q>p){
				for(lld j=0;j<q-1;j++){
					for(lld k=0;k<y;k++)
						cout<<'b';
					if(p>1){
						for(lld k=0;k<x;k++)
							cout<<'a';p--;}
						else if(p==1){
							for(lld k=0;k<m-(a*x);k++)
								cout<<'a';
						}
						else
							cout<<"*";
					}
					for(lld k=0;k<y;k++)
						cout<<'b';
				}
				if(q==p){
					for(lld j=0;j<q-1;j++){
						for(lld k=0;k<x;k++)
							cout<<'a';
						for(lld k=0;k<y;k++)
							cout<<'b';
					}
					for(lld k=0;k<m-(a*x);k++)
						cout<<'a';
					for(lld k=0;k<y;k++)
						cout<<'b';
				}
				cout<<endl;
				continue;
			}
		}
		bye;
	}

