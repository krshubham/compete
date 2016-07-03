#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;	
	while(t--){
		int n;
		cin>>n;
		int sum = 0;
		bool fail = false,max = false;
		vector<int> m(n);
		for (int i = 0; i < n; ++i)
		{
			cin>>m[i];
			if(m[i] <= 2){
				fail = true;
			}
			if(m[i] == 5){
				max = true;
			}
			sum+=m[i];
		}
		float avg = (float)sum/n;
		if(fail){
			cout<<"No"<<"\n";
		}
		else{
			if(avg>=4.0 && max){
				cout<<"Yes"<<"\n";
			}
			else{
				cout<<"No"<<"\n";
			}
		}
	}
	return 0;
}
