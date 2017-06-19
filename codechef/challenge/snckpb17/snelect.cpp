#include <iostream>
#include <string>
using namespace std;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string x;
		cin>>x;
		int len = x.size(),count1=0,count2=0,count3=0,i=0,count4=0;
		while(1)
		{
			if (x[i] == 'm')
			{
				if (x[i-1] == 's')
					x[i-1] = '0';
				
				else if (x[i-1] != 's' && x[i+1] == 's')
					x[i+1] = '0';
 
			}
			i++;
			if (i == len)
				break;
		}
		//cout<<"x= "<<x<<endl;
		for (int i=0;i<len;i++)
		{
			if (x[i] == 's')
				count1++;
			else if (x[i] == 'm')
				count2++;
		}
		if (count1>count2)
			cout<<"snakes"<<endl;
		else if (count1<count2)
			cout<<"mongooses"<<endl;
		else
			cout<<"tie"<<endl;
 
	}
} 