#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--){
		int a,b,c,diff;
		cin>>a>>b>>c;
		if(a-b == k || b-a ==k){
			diff = 0;
		}
		else if(a-b>k){
			while(a!=b && k!= 0){
				a++;
				k--;
			}
		}
		else if(b-a > k){
			while(a!=b && k!=0){
				b++;
				k--;
			}
		}
	}
	return 0;
}
