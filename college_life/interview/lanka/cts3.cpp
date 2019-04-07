/*
Given 'n' points, design an algorithm and write a C++ code to find the end points of the horizontal line that may be formed and that passess through maximum number of points. If there are more than one line that passess through maximum number of points then print the end points of the horizontal line that passes through maximum number of points and of minimum length.
For example, consider the twelve points (4, 4), (33, 10), (4, 20), (30, 20), (4, 25), (120, 20), (4, 30), (3, 10), (243, 10), (10, 4), (80, 20), (20, 10), (150, 20), there are two horizontal lines passing through four points. Their end points are (3,10) – (243, 10) (passing through (33, 10), (3, 10), (243, 10), (20, 10)) and (4,20) – (150, 20) (Passing through (4, 20), (30, 20), (120, 20), (80, 20), (150, 20)). Since both are of same length, print the line with minimum length and it is (4,20) and (150,20). 
*/
#include <iostream> 
#include <map>
#include <vector>
#include <algorithm>
#include <climits>
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

typedef long long int lli;
typedef vector<lli> vlli;

typedef map<lli,lli> mlli;
typedef vector<pair<lli,lli> > vplli;


int main(){
	lli t,n,a,b,c,d,e,f,x,y;
	cin>>n;
	map<lli,vlli> m;
	rep(i,n){
		cin>>x>>y;
		m[y].pb(x);
	}
	map<lli,vlli>::iterator it;
	c = INT_MAX;
	a = 0;
	for (it = m.begin(); it != m.end(); it++){
		a = max(a,(lli)it->second.size());
	}
	// cout<<a<<endl;
	lli x1,y1,x2,y2;
	for (it = m.begin(); it != m.end(); it++){
		if(it->second.size() == a){
			sort(all(it->second));
			if((it->second[it->second.size()-1] - it->second[0]) < c){
				y1 = it->first;
				y2 = it->first;
				x1 = it->second[0];
				x2 = it->second[it->second.size()-1];
				c = it->second[it->second.size()-1] - it->second[0];
			}
		}
	}
	cout<<x1<<endl;
	cout<<y1<<endl;
	cout<<x2<<endl;
	cout<<y2<<endl;
	bye;
}

