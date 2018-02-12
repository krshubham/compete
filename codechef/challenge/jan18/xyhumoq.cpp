#include <bits/stdc++.h>
using namespace std;

#define pb push_back
#define rep(i,n) for( int i = 0; i < n; i++ )

typedef long long ll;
string inp;
int calc(string s1,string s2){
	ll foo=0;
	rep(i,s1.length()){
		if(s1[i]!=s2[i]){
			foo++;
		}
	}
	return foo;
}

map<int,vector<string> > Mp;

int count(string a, string b){
	int m = a.size();
	int n = b.size();
	int dp[m + 1][n + 1] = { { 0 } };
	for (int i = 0; i <= n; ++i)
		dp[0][i] = 0;
	for (int i = 0; i <= m; ++i)
		dp[i][0] = 1;
	for (int i = 1; i <= m; i++){
		for (int j = 1; j <= n; j++){
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
			else{
				dp[i][j] = dp[i - 1][j];
			}
		}
	}
	return dp[m][n];
}

void solve(string str, int n){
	queue<string> q;
	q.push(str);
	int foo = INT_MAX;
	while (!q.empty()){
		string str = q.front();
		size_t index = str.find('?');
		if(index != string::npos){
			str[index] = '0';
			q.push(str);
			str[index] = '1';
			q.push(str);
		}
		else{
			string test = "10";
			int c = 0;
			while(test.size() <= str.size()){
				int x = count(str,test);
				c += x;
				test += "10";
			}
			Mp[c].pb(str);

		}
		q.pop();
	}
	if(Mp[n].size()==0){
		cout<<"NO";
	}
	else{
		ll foo=inp.size()-2;
		for(auto it=Mp[n].begin();it!=Mp[n].end();it++){
			foo=min(foo,(ll)calc(inp,*it));
		}
		cout<<"YES"<<endl;
		cout<<foo<<endl;
	}
	Mp.clear();
	cout<<endl;
}

int main(){
	int t,n;
	cin>>t;
	while(t--){
		cin>>inp;
		cin>>n;
		string test = "1";
		for (int i = 0; i < inp.size()-2; ++i){
			test += '?';
		}
      test += '0';
    solve(test,n);
  }	
  return 0;
}
