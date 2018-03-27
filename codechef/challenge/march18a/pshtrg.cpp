/*
	author: krshubham
	11.03.2018, 13:36 IST
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+5;
vector<long long int> t[4*MAXN];
long long int a[MAXN];
const int cap = 60; //max number of elements in a node


// Need to write custom merge function to keep only the top most 50 elements at each node at max;
// multiset<long long int,greater<long long int>> combine(multiset<long long int,greater<long long int>> a, multiset<long long int,greater<long long int>> b){
// 	vector<long long int> v1(a.begin(),a.end());
// 	vector<long long int> v2(a.begin(),a.end());
// 	multiset<long long int, greater<long long int>> temp;
// 	long long int x=0,y=0,c = 0;
// 	while(1){
// 		if(a.size() == 0) break;
// 		else if(b.size() == 0) break;
// 		if(v1[x] >= v2[y]){
// 			temp.insert(v1[x]);
// 			x++;
// 		}
// 		else{
// 			temp.insert(v2[y]);
// 			y++;
// 		}
// 		c++;
// 		if(c == 50 || v1.size() == x || v2.size() == y) break;
// 	}
// 	if(c < 50){
// 		if(v1.size() == x && v2.size() != y){
// 			while(1){
// 				temp.insert(v2[y]);
// 				y++;
// 				c++;
// 				if(c == 50 || y == v2.size()) break;
// 			}
// 		}
// 		else if(x != v1.size() && y == v2.size()){
// 			while(1){
// 				temp.insert(v1[x]);
// 				x++;
// 				c++;
// 				if(c == 50 || x == v1.size()) break;
// 			}
// 		}
// 	}
// 	return temp;
// }

// Reference from: https://e-maxx-eng.appspot.com/data_structures/segment_tree.html
// void build(long long int v, long long int l , long long int r){
// 	if(l == r){
// 		t[v].insert(a[l]);
// 	}
// 	else{
// 		long long int mid = (l+r)/2;
// 		build(v*2, l, mid);
// 		build(v*2+1, mid+1,r);
// 		multiset<long long int, greater<long long int>> temp;
// 		auto it = temp.begin();
// 		merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),inserter(temp,it));
// 		t[v].clear();
// 		int c = 0;
// 		for(auto it = temp.begin(); it != temp.end(); it++){
// 			t[v].insert(*it);
// 			if(c > 50) break;
// 		}
// 		// t[v] = combine(t[2*v],t[2*v+1]);
// 	}
// }

// void update(long long int v, long long int l, long long int r, long long int pos, long long int val){
// 	t[v].erase(t[v].find(a[pos]));
// 	t[v].insert(val);
// 	// cout<<"YES"<<endl;
// 	if(l != r){
// 		long long int mid = (l+r)/2;
// 		if(pos <= mid){
// 			update(2*v, l,mid,pos,val);
// 		}
// 		else{
// 			update(2*v+1,mid+1,r,pos,val);
// 		}
// 		t[v].clear();
// 		auto it = t[v].begin();
// 		merge(t[v*2].begin(), t[v*2].end(), t[v*2+1].begin(), t[v*2+1].end(),inserter(t[v],it));
// 	}
// 	else{
// 		a[pos] = val;
// 	}
// }


// // multiset<long long int> query(long long int v, long long int l, long long int r, long long int ql, long long int qr){
// // 	if(l == ql && r == qr){
// // 		return t[v];
// // 	}

// // 	long long int mid = (l+r)/2;
// // }

// multiset<long long int,greater<long long int>> query(long long int node, long long int start, long long int end, long long int l, long long int r) {
// 	if(r < start || end < l){
// 		multiset<long long int,greater<long long int>> temp;
// 		return temp;
// 	}
// 	if(l <= start and end <= r){
// 		return t[node];
// 	}
// 	long long int tm = (start + end) / 2;
// 	multiset<long long int,greater<long long int>> m1 = query(node*2, start, tm, l, r);
// 	multiset<long long int,greater<long long int>> m2 = query(node*2+1, tm+1, end,l, r);
// 	// return combine(m1,m2);
// 	// return m1;
// 	m1.insert(m2.begin(),m2.end());
// 	return m1;
// }


//Multisets never work, so try with vectors this time
vector<long long int> combine(vector<long long int> v1, vector<long long int> v2){
	vector<long long int> temp;
	int x=0,y=0,z=0;
	while(1){
		if(v1.size() == 0 || v2.size() == 0) break;
		if(v1[x] >= v2[y]){
			temp.push_back(v1[x]);
			x++;
			z++;
		}
		else{
			temp.push_back(v2[y]);
			y++;
			z++;
		}
		if(z == cap || x==v1.size() || y==v2.size()){
			break;
		}
	}
	if(z != cap){
		if(x == v1.size() && y != v2.size()){
			while(1){
				temp.push_back(v2[y]);
				y++;
				z++;
				if(z == cap || y == v2.size()) break;
			}
		}
		else if(x != v1.size() && y == v2.size()){
			while(1){
				temp.push_back(v1[x]);
				x++;
				z++;
				if(z == cap || x == v1.size()) break;
			}
		}
	}
	return temp;
}

vector<long long int> build(long long int node,long long int start ,long long int end){
	if(start==end){    
		t[node].push_back(a[end]);
		return t[node];
	}
	long long int mid= (start+end)/2;
	vector<long long int> a1,a2;
	// a1 = build(2*node,start,mid);
	// a2 = build(2*node+1,mid+1,end);
	// vector<long long int> temp = combine(a1,a2);
	t[node] = combine(build(2*node, start,mid), build(2*node+1,mid+1,end));
	return t[node];
}

vector<long long int> update(int node,int l,int r,int pos,int val){
	vector<long long int> a1,a2;
	int mid=(l+r)/2;
	if(l == r && l == pos){
		a[l]=val;
		t[node].clear();
		t[node].push_back(a[l]);
		return t[node];
	}
	else{
		if(mid >= pos){
			a1 = update(2*node,l,mid,pos,val);
			t[node] = combine(a1,t[2*node+1]);
		}
		else {
			a2 = update(2*node+1,mid+1,r,pos,val);
			t[node] = combine(t[2*node],a2);
		}
		return t[node];
	}
}

vector<long long int> query(int node,int l,int r,int start,int end){
	int mid=(l+r)/2;
	vector<long long int> temp;
	if(start >r || end < l){
		return temp;
	}
	if(l >= start && end >= r){
		return t[node];
	}
	return(combine(query(2*node,l,mid,start,end),query(2*node+1,mid+1,r,start,end)));
}

int main(){
	long long int n,q;
	cin>>n>>q;
	for (long long int i = 1; i <= n; ++i){
		cin>>a[i];
	}
	build(1,1,n);
	long long int x,y,z;
	while(q--){
		cin>>x>>y>>z;
		if(x == 1){
			update(1,1,n,y,z);
		}
		else{
			auto v = query(1,1,n,y,z);
			if(v.size() < 3){ // the great evil
				cout<<0<<endl;
				continue;
			}
			bool fl = false;
			for (long long int i = 0; i < v.size()-2; ++i){
				if(v[i+1]+v[i+2] <= v[i]) continue;
				else{
					fl = true;
					cout<<(v[i]+v[i+1]+v[i+2])<<endl;
					break;
				}
			}
			if(!fl){
				cout<<0<<endl;
			}
		}
	}
	return 0;
}
