#include <iostream>
#include <cstdlib>	
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef double dbl;


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	lli t;
	cin>>t;
	while(t--){
		lli count = 0;
		lli n;
		cin>>n;
		for (int i = 0; i < n; ++i){
			for (int j = 0; j < n; ++j){
				lli a;
				cin>>a;
				if(a == 1){
					count++;
				}
			}
		}
		lli bw = 0;
		if(count > n){
			bw++;
			count -= n;
		}
		while(--n > 1){
			if (count > 2*n) {
				bw++;
				count -= 2*n;
			}
			else
				break;
		}
		cout<<bw<<endl;
	}
	return 0;
}
