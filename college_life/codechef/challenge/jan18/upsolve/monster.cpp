#pragma comment (linker, "/stack:20000000")
#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
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
#define endl '\n'

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef unsigned long long ull;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef unordered_map<lli,lli> umlli;
typedef vector<pair<lli,lli> > vplli;

vector<string> split(string str,string sep){
	char* cstr=const_cast<char*>(str.c_str());
	char* current;
	vector<string> arr;
	current=strtok(cstr,sep.c_str());
	while(current!=NULL){
		arr.push_back(current);
		current=strtok(NULL,sep.c_str());
	}
	return arr;
}

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

const lli N_MAX = (1<<17) + 1;
const lli MAX = (1e9) + 3;
const lli mask = (1<<17)-1;
const lli BIT = 18;
const lli Q_MAX = (1<<18) + 1;

lli answer[Q_MAX];
lli h[N_MAX];
lli query[Q_MAX][2];
lli bitmask[Q_MAX];

int main(){
	lli n;
	cin>>n;
	for(lli i=0;i<n;i++) {
		cin>>h[i];
	}
	lli q;
	cin>>q;
	for(lli i=0;i<q;i++){
		//x,y for a query
		cin>>query[i][0]>>query[i][1];

		//trim to 2^17
		query[i][0] &= mask;
	}

	lli block_size = 1000, total_block = q/block_size + 1, index = 0;
	lli duplicate;
	
	for(lli in_block = 0; in_block<total_block; in_block++){
		memset(bitmask, 0 , sizeof(bitmask));

		duplicate = index;
		for(lli i = 0;(i<block_size) && (index<q); i++,index++){
			// Store the updates by the query.
			bitmask[query[index][0]] += query[index][1];
		}
		
		for(lli bit = 0;bit<BIT;bit++){
			for(lli i=mask;i>=0;i--){
				if(!((i>>bit)&1)){
					bitmask[i]+=bitmask[i^(1<<bit)];
					bitmask[i]=min(bitmask[i],MAX);
				}
			}
		}
		lli pos = duplicate;
		for(lli i=0;i<n;i++){
			if(h[i]<=0){
				continue;
			}
			
			h[i]-=bitmask[i];

			if(h[i]>0){
				continue;
			}
			lli current = 0;
			duplicate = pos;
			for(lli j=0;(j<block_size) && (duplicate<q); j++,duplicate++){
				if((i&query[duplicate][0])==i){
					current+=query[duplicate][1];
				}
				if(((bitmask[i] + h[i]) - current)<=0){
					answer[duplicate]++;
					break;
				}
			}
		}
	}
	lli left = n;
	for(lli i=0;i<q;i++){
		left = left - answer[i];
		cout<<left<<endl;
	}
	bye;
} 