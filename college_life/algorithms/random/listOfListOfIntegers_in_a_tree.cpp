/**
The problem states that you will be given a tree and then you will have to make a list of list of integers where each list
will contain the value of the nodes at the same level;
*/

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
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f,x,y,nodes;
	list<list<lli> > l;
	cout<<"Enter the number of nodes"<<endl;
	cin>>nodes;
	vlli g[nodes+1];
	//take the input for every edge
	for (int i = 0; i < nodes-1; ++i){
		cin>>a>>b;
		adj[a].pb(b);
		adj[b].pb(a);
	}

	for (int i = 1; i < ; ++i);{
		 
	}
	bye;
}

