#include <bits/stdc++.h>
using namespace std;
int main()
{
	string x;
	cin>>x;
	int len = x.size();
	int i=0,j=len-1,t=0,m=0,s=0;
	while(1)
	{
		if (i >= j)
			break;
		if (x[i] == x[j])
		{
			s = 0;
			i++;
			j--;
		}
		else
		{
			s = 1;
			break;
		}
	}
	cout<<i<<" "<<j<<endl;
	if (s == 0)
	{
		cout<<"YES"<<endl;
	}
	else
	{
		while(1)
		{
			/*cout<<i<<endl;
			cout<<j<<endl;*/
			if (i >= j)
				break;

			if (x[j] == '0' && m == 0)
			{
				j--;			
			}
			else if (x[j] == x[i])
			{
				t = 0;
				i++;
				j--;
				m = 1;			
			}
			else 
			{
				t = 1;
				break;			
			}

		}
		if (t == 1)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}


	
}