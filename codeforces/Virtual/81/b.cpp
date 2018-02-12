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
inline long long int_in (){
	long long x;
#ifdef LOCAL
	scanf ("%lld", &x);
#else
	scanf ("%I64d", &x);
#endif

	return x;
}

inline void int_out (long long x, char end = '\n'){
#ifdef LOCAL
	printf ("%lld%c", x, end);
#else
	printf ("%I64d%c", x, end);
#endif
}

// End of prewritten code.

const int MAX = 10;

int N, K, A, level [MAX], loyal [MAX];
double best = 0;

double probability ()
{
	double total = 0;

	for (int mask = 0; mask < 1 << N; mask++)
	{
		double p = 1;
		int bad = 0;

		for (int i = 0; i < N; i++)
			if (mask & 1 << i)
				p *= loyal [i] / 100.0;
			else
			{
				p *= 1 - loyal [i] / 100.0;
				bad += level [i];
			}

			if (2 * __builtin_popcount (mask) > N)
				total += p;
			else
				total += p * A / (A + bad);
		}

		return total;
	}

	void go (int num, int k)
	{
		if (num == N)
		{
			best = max (best, probability ());
			return;
		}

		go (num + 1, k);

		if (k > 0 && loyal [num] < 100)
		{
			loyal [num] += 10;
			go (num, k - 1);
			loyal [num] -= 10;
		}
	}

	int main (){
		cin>>N>>K>>A;

		for (int i = 0; i < N; i++)
			scanf ("%d %d", level + i, loyal + i);

		go (0, K);
		printf ("%.12lf\n", best);
		return 0;
	}