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
	string s1,s2;
	cin>>s1>>s2;
	int n;
	cin>>n;
	//cout<<s1[0]<<s2[0];
	n=n%4;
	int a = (int)s1[0];
	int b = (int)s2[0];
	int f1=0,f2=0;
	int x=a;
	for(int i=1;i<=n;i++)
	{
		if(a==94)
			a=62;
		else if(a==62)
			a=118;
		else if(a==118)
			a=60;
		else if(a==60)
			a=94;
	}
	if(a==b)
	{
		f1=1;
	}
	for(int i=1;i<=n;i++){
		if(x==94)
			x=60;
		else if(x==62)
			x=94;
		else if(x==118)
			x=62;
		else if(x==60)
			x=118;
	}
	if(x==b)
	{
		f2=1;
	}
	if(f1==1 && f2==1){
		cout<<"undefined"<<endl;
		return 0;
	}
	if(f1)
		cout<<"cw\n";
	else if(f2)
		cout<<"ccw\n";
	else
		cout<<"undefined\n";
	return 0;

}