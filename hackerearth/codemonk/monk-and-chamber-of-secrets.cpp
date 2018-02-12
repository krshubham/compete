#include <bits/stdc++.h>
#define ll long long int
#define pb push_back
#define endl '\n'
#define mp make_pair
using namespace std;
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int n,x,z;
	deque<int> deq;
	deque<pair<int,int>> deq2;
	deque<pair<int,int>>::iterator itr;
	pair<int,int> p;
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>z;
		deq.pb(z);
		deq2.pb(mp(z,i+1));
	}
	for(int i=1;i<=x;i++){
		z=deq2.size();
		if(z<x){
			deque<pair<int,int>> deq3;
			int l=deq2.size();
			for(int j=0;j<l;j++){
				p=deq2.front();
				deq2.pop_front();
				deq3.pb(p);
			}
			itr=deq3.begin();
			for(auto itr2=deq3.begin();itr2!=deq3.end();itr2++){
				if((*itr2).first>(*itr).first)
					itr=itr2;
			}
			cout<<(*itr).second<<' ';
			deq3.erase(itr);
			l=deq3.size();
			for(int j=0;j<l;j++){
				p=deq3.front();
				if(p.first!=0)
					p.first=p.first-1;
				deq2.pb(p);
				deq3.pop_front();
			}
		}
		else{
			deque<pair<int,int>> deq3;
			int l;
			for(int j=0;j<x;j++){
				p=deq2.front();
				deq2.pop_front();
				deq3.pb(p);
			}
			itr=deq3.begin();
			for(deque<pair<int,int>>::iterator itr2=deq3.begin();itr2!=deq3.end();itr2++){
				if((*itr2).first>(*itr).first)
					itr=itr2;
			}
			cout<<(*itr).second<<' ';
			deq3.erase(itr);
			l=deq3.size();
			for(int j=0;j<l;j++){
				p=deq3.front();
				if(p.first!=0)
					p.first=p.first-1;
				deq2.pb(p);
				deq3.pop_front();
			}
		}
	}
}