#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		vector<long long>v1;
		vector<long long>::iterator it1;
		long n,y,m = 1,temp,i=0,count=0,x;
		cin>>n>>x;
		long long sum = 0;
		
		while(1){
			y = x%10;
			if (y == 0)
				break;

			sum += y*pow(4,i);
			x /= 10;
			i++;
			if (i>n)
				break;
		}
		if (i>n)
			continue;
		i = 0;

		while(1){
			m *=2;
			if (sum<m)
				break;
			temp = sum%m;
			v1.push_back(temp);
			i++;
		}
		sort(v1.begin(),v1.end());
		int j = 0;
		while(1){
			temp = v1[j];
			j++;
			count++;
			while(v1[j] == temp)
			{
				count++;
				j++;
				if (j == i)
					break;
			}
			cout<<count;
			count = 0;
			if (j == i)
				break;

		}
		cout<<endl;
	}


}