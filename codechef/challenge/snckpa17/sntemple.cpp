#include <bits/stdc++.h>
using namespace std;

#define mp make_pair

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


vector<pair<int, int> > p1, p2;
vector<int> v;
int n;

void build(int node, int left, int right) {
	if (left == right) {
		p1[node] = make_pair(v[left] - left - 1, left);
		p2[node] = make_pair(v[right] - (n - right), right);
		return;
	}
	int mid = (left + right) / 2;
	build(2 * node + 1, left, mid);
	build(2 * node + 2, mid + 1, right);
	p1[node] = min(p1[2 * node + 1], p1[2 * node + 2]);
	p2[node] = min(p2[2 * node + 1], p2[2 * node + 2]);
}

pair<int, int> query(const vector<pair<int, int> > &seg, int node, int left, int right, int from, int to) {
	if (from > right || to < left) return make_pair(INT_MAX, INT_MAX);
	if (from <= left && to >= right) return seg[node];
	int mid = (left + right) / 2;
	return min(query(seg, 2 * node + 1, left, mid, from, to), query(seg, 2 * node + 2, mid + 1, right, from, to));
}

void solve(int n) {
	lli c;
	v.resize(n);
	for (int i = 0; i < n; ++i){
		cin>>c;
		v[i] = c;
	}
	p1.resize(4 * n);
	p2.resize(4 * n);
	build(0, 0, n-1);
	int maximalP = 0;
	for (int i = 0; i < n; i++) {
		auto left = query(p1, 0, 0, n - 1, 0, i), right = query(p2, 0, 0, n - 1, i, n - 1);
		int l = max(0, -left.first), r = n - 1 + min(0, right.first), p = min(i - l, r - i) + 1;
		maximalP = max(maximalP, p);
	}
	ll fin = 0;
	for (int x: v) fin += x;
	fin -= (ll)maximalP * maximalP;
	// fin--;
	cout<<fin<<endl;
}

int main() {
	lli t;
	cin>>t;
	while(t--){
		cin>>n;
		solve(n);
	}
	return 0;
}