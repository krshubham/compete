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
	lli t,a,b,c,d,e,cnt,h;
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
			for (int i = 0; i < a; ++i){
				if(arr[i] < c) v.push_back(c - arr[i]);
				else{
					cnt++;
					continue;
				}
			}
			if(v.size() != 0){
				sort(v.begin(),v.end());
				// print(v);
				h = 0;
				hi = v.begin();
				l = v.end() - 1;					
				while(l != hi){
					print(v);
					cout<<"HHHHHHH : "<<h<<endl;
					cout<<"V{HHHHHH}: "<<v[h]<<endl;
					cout<<"v[llllllll]: "<<*l<<endl;
					if(v[h] != 0){
						cout<<"ELse me gya main"<<endl;
						v[h]--;
						l--;
					}
					else{
						cout<<"Haan zero mila ab, so ab h badha raha hun, agli baar v[h] = 2 aana chaiye"<<endl;
						++h;
						++hi;
						cnt++;
					}
				}
				cout<<"Hello "<<cnt<<endl;
			}
			else{
				cout<<a<<endl;
			}
			v.clear();
		}
	}
	return 0;
}
