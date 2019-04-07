#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli a,b,c,d,e,f,t;
	cin>>t;
	string s;
	while(t--){
		cin>>a;
		vector<string> v;
		for (int i = 0; i < 2; ++i){
			cin>>s;
			v.push_back(s);
		}
		f = 0;
		lli l = 0, r=a;
		while(v[0][l] == '.' && v[1][l] == '.') l++;
		while(v[0][r-1] == '.' && v[1][r-1] == '.') r--;
		vector<string> finalstr(2);
		for (int i = 0; i < 2; i++){
			//trim the string
			finalstr[i] = string(v[i].begin() + l, v[i].begin() + r);
		}
		f = finalstr[0].size();
		vector< vector<int> > check(2, vector<int>(f + 1));
		check[0][0] = check[1][0] = 1;
		for (int i = 0; i < f; i++) {
			cout<<finalstr[0][i]<<" : "<<finalstr[1][i]<<endl;
			if (finalstr[0][i] == '.') {
				if (finalstr[1][i] == '.') check[0][i + 1] = check[1][i + 1] = 0;	
				else {
					check[0][i + 1] = 0;
					check[1][i + 1] = check[1][i];
				}
			} 
			else {
				if (finalstr[1][i] == '.') {
					check[0][i + 1] = check[0][i];
					check[1][i + 1] = 0;
				} else {
					check[0][i + 1] = check[1][i];
					check[1][i + 1] = check[0][i];
				}
			}
			// cout<<"check value"<<endl;
			// for (int i = 0; i <f; ++i){
			// 	cout<<check[0][i]<<" : "<<check[1][i]<<endl;
			// }
		}	
		int ans = check[0][f] || check[1][f];
		ans ? cout<<"yes"<<endl : cout<<"no"<<endl ;
	}
	return 0;
}

