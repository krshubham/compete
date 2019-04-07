#include<bits/stdc++.h> 
using namespace std;
int a[100010];
int main(){
	int n, k;
	cin >> n >> k;
	for(int i = 0; i < n; i++) cin >> a[i];
		if(k >= 3) cout << *max_element(a, a + n);
	else if (k == 1)cout << *min_element(a, a + n);
	else{
		cout << max(a[0], a[n - 1]);
	}
}