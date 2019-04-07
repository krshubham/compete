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

inline vector<string> split(string str,string sep){char* cstr=const_cast<char*>(str.c_str());char* current;vector<string> arr;current=strtok(cstr,sep.c_str());while(current!=NULL){arr.push_back(current);current=strtok(NULL,sep.c_str());}return arr;}
inline bool isPrime(lli n){if (n <= 1){return false;}if (n <= 3)  {return true;}if (n%2 == 0 || n%3 == 0) {return false;}for (int i=5; i*i<=n; i=i+6){if (n%i == 0 || n%(i+2) == 0){return false;}}return true;}
inline lli power(lli x,lli y,lli p){int res=1;x=x%p;while(y>0){if(y&1)res=(res*x)%p;y = y>>1;x = (x*x) % p;}return res;}
#include<bits/stdc++.h>
using namespace std;

void SieveOfEratosthenes(int n, bool prime[],
	bool primesquare[], int a[])
{
    // Create a boolean array "prime[0..n]" and
    // initialize all entries it as true. A value
    // in prime[i] will finally be false if i is
    // Not a prime, else true.
	for (int i=2; i<=n; i++)
		prime[i] = true;

    // Create a boolean array "primesquare[0..n*n+1]"
    // and initialize all entries it as false. A value
    // in squareprime[i] will finally be true if i is
    // square of prime, else false.
	for (int i=0; i<=(n*n+1); i++)
		primesquare[i] = false;

    // 1 is not a prime number
	prime[1] = false;

	for (int p=2; p*p<=n; p++)
	{
        // If prime[p] is not changed, then
        // it is a prime
		if (prime[p] == true)
		{
            // Update all multiples of p
			for (int i=p*2; i<=n; i += p)
				prime[i] = false;
		}
	}

	int j = 0;
	for (int p=2; p<=n; p++)
	{
		if (prime[p])
		{
            // Storing primes in an array
			a[j] = p;

            // Update value in primesquare[p*p],
            // if p is prime.
			primesquare[p*p] = true;
			j++;
		}
	}
}

// Function to count divisors
int countDivisors(int n)
{
    // If number is 1, then it will have only 1
    // as a factor. So, total factors will be 1.
	if (n==1)
		return 1;

	bool prime[n+1], primesquare[n*n+1];

    int a[n];  // for storing primes upto n

    // Calling SieveOfEratosthenes to store prime
    // factors of n and to store square of prime
    // factors of n
    SieveOfEratosthenes(n, prime, primesquare, a);

    // ans will contain total number of distinct
    // divisors
    int ans = 1;

    // Loop for counting factors of n
    for (int i=0;; i++)
    {
        //  a[i] is not less than cube root n
    	if (a[i]*a[i]*a[i] > n)
    		break;

        // Calculating power of a[i] in n.
        int cnt = 1; // cnt is power of prime a[i] in n.
        while (n%a[i]==0)  // if a[i] is a factor of n
        {
        	n = n/a[i];
            cnt = cnt+1; // incrementing power
        }

        // Calculating number of divisors
        // If n = a^p * b^q then total divisors of n
        // are (p+1)*(q+1)
        ans = ans*cnt;
    }

    // if a[i] is greater than cube root of n

    // First case
    if (prime[n])
    	ans = ans*2;

    // Second case
    else if (primesquare[n])
    	ans = ans*3;

    else if (n != 1)
    	ans = ans*4;

    return ans;
}




int64_t arr[100006];
int64_t t[262200];
int64_t lazy[262200];

void build(int64_t node, int64_t a, int64_t b)
{
	if(a>b) return;
	if (a==b)
	{
		t[node]=arr[a];
		return;
	}
	
	build(node*2, a, (a+b)/2);
	build(node*2+1,(a+b)/2+1,b);
	
	t[node]=t[node*2]+t[node*2+1];
}

int64_t query(int64_t node, int64_t a, int64_t b, int64_t i, int64_t j)
{
	if(a>b||a>j||b<i) return 0;
	if (lazy[node] !=0 )
	{
		t[node]+=lazy[node]*(b-a+1);
		if (a!=b)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	
	if (a>=i && b<=j) return t[node];
	
	int64_t q1=query(node*2, a, (a+b)/2, i, j);
	int64_t q2=query(node*2+1, (a+b)/2+1, b, i, j);
	
	return q1+q2;
}

void update(int64_t node, int64_t a, int64_t b, int64_t i, int64_t j, int64_t inc)
{
	if(a>b) return;
	if (lazy[node]!=0)
	{
		t[node]+=lazy[node]*(b-a+1);
		if (a!=b)
		{
			lazy[node*2]+=lazy[node];
			lazy[node*2+1]+=lazy[node];
		}
		lazy[node]=0;
	}
	if(a>b||a>j||b<i) return;
	
	if (a>=i && b<=j)
	{
		t[node]+=inc*(b-a+1);
		if (a!=b)
		{
			lazy[node*2]+=inc;
			lazy[node*2+1]+=inc;
		}
		return;
	}
	
	update(node*2, a, (a+b)/2, i, j, inc);
	update(node*2+1, (a+b)/2+1, b,i, j, inc);
	t[node] = t[node*2] + t[node*2+1];
}
int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	int64_t t,n,qu,q,p,a; cin>>t;
	int64_t inc;
	while(t--){
		cin>>n>>qu;
		build(1,0,n-1);
		for (int i = 0; i < 262200; ++i) lazy[i]=0;
			while(qu--){
				cin>>a;
				if (a==0){
					cin>>p>>q>>inc;
					update(1,0,n-1,p-1,q-1,inc);
				}
				else{
					cin>>p>>q;
					cout<<query(1,0,n-1,p-1,q-1)<<endl;
				}
			}

		}
		return 0;
	} 
