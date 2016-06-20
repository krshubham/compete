#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	std::ios::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		vector<int> marks;
		int n,e,k;
		long m;
		cin>>n>>k>>e>>m;
		while(--n){
			int a,sum=0;
			for (int i = 0; i < e; ++i)
			{
				cin>>a;
				sum = sum+a;		
			}
			marks.push_back(sum);
		}
		sort(marks.begin(),marks.end());
		int a,b;
		cin>>a>>b;
		if(marks)
		else{
			int needed = marks[k-1] - (a+b) + 1;
			cout<<needed<<endl;
		}
	}
	//to add impossible
	return 0;
}
