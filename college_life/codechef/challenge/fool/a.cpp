
#include <bits/stdc++.h>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef unsigned long long ull;


bool isPrime[(lli)1e6+5];

bool SieveOfEratosthenes(int n, bool isPrime[]){
	isPrime[0] = isPrime[1] = false;
	for (int i=2; i<=n; i++)
		isPrime[i] = true;

	for (int p=2; p*p<=n; p++){
		if (isPrime[p] == true){
			for (int i=p*2; i<=n; i += p)
				isPrime[i] = false;
		}
	}
}
void findPrimePair(int n){
	for (int i=0; i<n; i++){
		if (isPrime[i] && isPrime[n-i]){
			cout << i << " " << (n-i)<<endl;
			return;
		}
	}
	cout<<0<<" "<<n<<endl;
}

int main(){
	int t;
	cin>>t;
	int n;
	SieveOfEratosthenes((lli)1e6+5, isPrime);
	while(t--){
		cin>>n;
		findPrimePair(n);
	}
	return 0;
}