#include <bits/stdc++.h>

using namespace std;


int main() {
	int T;
	cin>>T;
	while (T--) {
		int n, K;
		cin>>n>>K;

		vector<int> votes(n);
		vector<int> a;
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			assert(x >= 1 && x <= n);
			x--;
			a.push_back(x);
			votes[x]++;
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (a[i] == i) continue;
			if (votes[i] >= K) {
				ans++;
			}
		}

		cout<<ans<<endl;
	}

	return 0;
}