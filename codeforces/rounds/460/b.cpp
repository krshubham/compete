#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
	ll n;
	cin>>n;
	if(n==1)
		cout<<19<<endl;
	else if(n==2)
		cout<<28<<endl;
	else
	{
		int ans=0;n=n-2;int c = 30;
		while(n>0)
		{
			int k = c;int s = 0;
			while(k!=0)
			{
				int d = k%10;
				s+=d;
				k=k/10;
			}
			if(s==10)
			{
				ans = c;
				n--;
			}
			c++;
		}
		cout<<ans<<endl;
	}
}