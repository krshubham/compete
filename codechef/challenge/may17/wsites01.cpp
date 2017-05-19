#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <string>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;


lli arr[200000][27];
lli nxt = 1;
set<string> block;
lli bs = 0;

lli check(string s) {
	lli v = 0;
	for (int i = 0; i < s.size(); ++i){
		lli j = s[i] - 'a';// getting the int value of alpha
		if (arr[v][j] == -1) {
			block.insert(s.substr(0,i+1));
			bs++;
			return 1;
		}
		v = arr[v][j];
	}
	return 0;
}

int main() {
	lli t;
	cin>>t;
	string c,s;
	vector<string> r;

	// set all the values to -1
	memset(arr, -1, sizeof(arr));


	while(t--){
		cin>>c>>s;
		if (c == "+"){
			lli v = 0;
			for (int i = 0; i < s.size(); ++i){
				int j = s[i] - 'a';
				if (arr[v][j] == -1){
					arr[v][j] = nxt++;
				}
				v = arr[v][j];
			}
		} 
		else{
			r.push_back(s);
		}
	}

	for (int i = 0; i < r.size(); ++i){
		if (!check(r[i])) {
			cout<<-1<<endl;
			return 0;
		}
	}
	cout<<bs<< endl;
	set<string>::iterator it;
	for (it = block.begin(); it != block.end(); it++)
		cout<<*it <<endl;

	return 0;
}