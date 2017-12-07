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
#define rrep(i,n) for(int i = n - 1 ; i >= 0 ; i--)
#define crep(i,a,b) for( int i = a; i <= b; i++ )
#define endl '\n'
#define fi first
#define se second
#define sz(x) ((int)x.size())
#define sqr(x) ((x)*(x))

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef unsigned long long ull;
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
string text;
void findLongestPalindromicString(){
	int N = strlen(text);
	if(N == 0)
		return;
	N = 2*N + 1;
	int L[N];
	L[0] = 0;
	L[1] = 1;
	int C = 1;
	int R = 2;
	int i = 0;
	int iMirror;
	int expand = -1;
	int diff = -1;
	int maxLPSLength = 0;
	int maxLPSCenterPosition = 0;
	int start = -1;
	int end = -1;
	for (i = 2; i < N; i++) {
		iMirror  = 2*C-i;
		expand = 0;
		diff = R - i;
		if(diff > 0) {
			if(L[iMirror] < diff)
				L[i] = L[iMirror];
			else if(L[iMirror] == diff && i == N-1)
				L[i] = L[iMirror];
			else if(L[iMirror] == diff && i < N-1){
				L[i] = L[iMirror];
				expand = 1;
			}
			else if(L[iMirror] > diff){
				L[i] = diff;
                expand = 1;  // expansion required
            }
        }
        else{
        	L[i] = 0;
            expand = 1;  // expansion required
        }

        if (expand == 1){
        	while (((i + L[i]) < N && (i - L[i]) > 0) && 
        		( ((i + L[i] + 1) % 2 == 0) || 
        			(text[(i + L[i] + 1)/2] == text[(i-L[i]-1)/2] )))
        	{
        		L[i]++;
        	}
        }

        if(L[i] > maxLPSLength){
        	maxLPSLength = L[i];
        	maxLPSCenterPosition = i;
        }
        if (i + L[i] > R) 
        {
        	C = i;
        	R = i + L[i];
        }
        //Uncomment it to print LPS Length array
        //printf("%d ", L[i]);
    }
    //printf("\n");
    start = (maxLPSCenterPosition - maxLPSLength)/2;
    end = start + maxLPSLength - 1;
    //printf("start: %d end: %d\n", start, end);

    // printf("LPS of string is %s : ", text);
    // for(i=start; i<=end; i++)
    // 	printf("%c", text[i]);
    // printf("\n");
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y;
	
	bye;
}

