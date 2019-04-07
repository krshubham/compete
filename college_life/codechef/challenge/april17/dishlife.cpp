#include <set>
#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

set<int>s;
int main()
{
	int t;
	cin>>t;
	while(t--){
		s.clear();
		int n,k,m,x,sf=0,sflag=0;
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>m;
			sf = 0;
			for(int j=0;j<m;j++)
			{
				cin>>x;
				if(s.find(x)!=s.end())
					sf++;
				s.insert(x);
			}
			if(sf == m)
				sflag = 1;
		}
		if(s.size()!=k)
			cout<<"sad"<<endl;
		else if(sflag==1)
			cout<<"some"<<endl;
		else
			cout<<"all"<<endl;
	}
	return 0;
}