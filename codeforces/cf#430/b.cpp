#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pl;

int a[1010][1010];
int dp[1010][1010];
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			cin>>a[i][j];

		for(int i=0;i<n;i++)
			dp[0][i] = a[0][i];

		for(int i=1;i<n;i++)
		{
			for(int j=0;j<n;j++)
			{
				if(j == 0)
					dp[i][j] = max(dp[i-1][j],dp[i-1][j+1]) + a[i][j];
				else if(j == n-1)
					dp[i][j] = max(dp[i-1][j],dp[i-1][j-1])+a[i][j];
				else
					dp[i][j] = max(dp[i-1][j],max(dp[i-1][j-1],dp[i-1][j+1])) + a[i][j];
			}
		}
		int ans = 0;
		for(int i=0;i<n;i++)
			ans = max(ans,dp[n-1][i]);
		cout<<ans<<endl;
		return 0;
	}