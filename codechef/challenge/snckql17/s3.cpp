#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<long long int> vlli;

void print(vlli v){
	vlli::iterator i;
	for (i = v.begin(); i != v.end(); i++){
		cout<<*i<<endl;
	}
}

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli t,a,b,c,d,e,cnt,h,sum;
	cin>>t;
	vlli::iterator it,l,hi;
	while(t--){
		cin>>a>>b;
		lli arr[a];
		vlli v;
		for (int i = 0; i < a; ++i){
			cin>>arr[i];
		}
		for (int i = 0; i < b; ++i){
			cin>>c;
			cnt=0;
			sum = 0;
			for (int j = 0; j < a; ++j){
				if(arr[j] < c) v.push_back(c - arr[j]);
				else{
					cnt++;
					continue;
				}
			}
			e = v.size();
			if(e > 1){
				sort(v.begin(),v.end());
				for (int j = 0; j < e; ++j){
					sum += v[j];
					if(sum <= (e - (j+1))){
						cnt++;
					}
					else{
						cout<<cnt<<endl;
						break;
					}
				}
			}
			else if(e == 1){
				cout<<cnt<<endl;
			}
			else{
				cout<<a<<endl;
			}
			v.clear();
		}
	}
	return 0;
}
