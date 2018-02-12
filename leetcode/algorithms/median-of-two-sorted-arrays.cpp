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

double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
	if(nums1.size() > nums2.size()){
		return findMedianSortedArrays(nums2,nums1);
	}
	//time complexity O(log(size(num1)));
	int x = nums1.size();
	int y = nums2.size();
	int low = 0;
	int high = x;
	while(low <= high){
		cout<<low<<" "<<high<<endl;
		int partX = (x+y)/2;
		int partY = (x+y+1)/2 - partX;
		int maxLeftX = (partX == 0) ? INT_MIN : nums1[partX - 1];
		int minRightX = (partX == x) ? INT_MAX : nums1[partX];
		int maxLeftY = (partY == 0) ? INT_MIN : nums2[partY - 1];
		int minRightY = (partY == y) ? INT_MAX : nums2[partY];
		if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
			if ((x + y) % 2 == 0) {
				return ((double)max(maxLeftX, maxLeftY) + min(minRightX, minRightY))/2;
			} 
			else {
				return (double)max(maxLeftX, maxLeftY);
			} 
			if (maxLeftX > minRightY) {
				high = partX - 1;
			} 
			else {
				low = partX + 1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,a,b,c,d,e,f;
	int x[] = {1, 3, 8, 9, 15};
	int y[] = {7, 11, 19, 21, 18, 25};
	vector<int> v1(x,x+5);
	vector<int> v2(y,y+6);
	cout<<findMedianSortedArrays(v1,v2)<<endl;
	bye;
}

