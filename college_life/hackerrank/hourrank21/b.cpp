#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long int lli;


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli s,m,d,a,b,cnt,sum;
	vector<lli> v;
	cin>>s>>m>>d;
	lli i = 1;
	cnt = 0;
	lli arr[m-1];
	for (int i = 1; i < m; ++i){
		arr[i-1] = i;
	}
	for (int i = 0; i < m-1; ++i){
		sum = 0;
		while(sum != s){
			sum += arr[i];
			v.push_back(arr[i]);
		}
	}
	lli currSum = v[0];
	lli start=0;
	lli end=0;
	lli givenSum = s;
	for (int i = 0; i < v.size(); ++i){
		cout<<v[i]<<endl;
	}
	while (end < v.size()){
		if (currSum == givenSum){
			cnt++;
		}

		if (currSum <= givenSum)
		{
			end++;
			if (end < v.size())
				currSum = currSum + v[end];
		}
		else
		{
			currSum = currSum - v[start];
			start++;
		}
	}
	cout<<cnt<<endl;
	return 0;
}
