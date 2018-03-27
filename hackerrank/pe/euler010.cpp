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

const long long MAX_SIZE = 1000005;
vector<ulli>isprime(MAX_SIZE , true);
vector<ulli>prime;
vector<ulli>SPF(MAX_SIZE);

void manipulated_seive(ulli N){
    // 0 and 1 are not prime
	isprime[0] = isprime[1] = false ;

    // Fill rest of the entries
	for (ulli i=2; i<N ; i++){
        // If isPrime[i] == True then i is
        // prime number
		if (isprime[i]){
            // put i into prime[] vector
			prime.push_back(i);

            // A prime number is its own smallest
            // prime factor
			SPF[i] = i;
		}

        // Remove all multiples of  i*prime[j] which are
        // not prime by making isPrime[i*prime[j]] = false
        // and put smallest prime factor of i*Prime[j] as prime[j]
        // [ for exp :let  i = 5 , j = 0 , prime[j] = 2 [ i*prime[j] = 10 ]
        // so smallest prime factor of '10' is '2' that is prime[j] ]
        // this loop run only one time for number which are not prime
		for (ulli j=0;
			j < (int)prime.size() &&
			i*prime[j] < N && prime[j] <= SPF[i];
			j++)
		{
			isprime[i*prime[j]]=false;

            // put smallest prime factor of i*prime[j]
			SPF[i*prime[j]] = prime[j] ;
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	manipulated_seive(1000001);
	ulli t,n,a,b,c,d,e,f,x,y;
	cin>>t;
	while(t--){
		cin>>n;
		c = 0;
		for (int i = 2; i <= n; i++){
			if (isprime[i]){
				c += i;
			}
		}
		cout<<c<<endl;
	}
	bye;
}

