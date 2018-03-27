/*
* @Author: Kumar Shubham
* @Date:   2018-03-12 20:57:36
* @Last Modified by:   Kumar Shubham
* @Last Modified time: 2018-03-12 21:02:57
*/
#include <bits/stdc++.h>
using namespace std;

const long long MAX_SIZE = 1000001;
vector<long long >isprime(MAX_SIZE , true);
vector<long long >prime;
vector<long long >SPF(MAX_SIZE);

void pre(int N){
    isprime[0] = isprime[1] = false ;
    for (long long int i=2; i<N ; i++){
        if (isprime[i]){
            prime.push_back(i);
            SPF[i] = i;
        }
        for (long long int j=0;j < (int)prime.size() &&i*prime[j] < N && prime[j] <= SPF[i];j++){
            isprime[i*prime[j]]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}

int main(int argc, char const *argv[]){
	int t;
	cin>>t;
	int l,r;
	pre(MAX_SIZE);
	while(t--){
		cin>>l>>r;
		int cnt = 0;
		for (int i = l; i <= r; ++i){
			if(isprime[__builtin_popcount(i)]){
				cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
