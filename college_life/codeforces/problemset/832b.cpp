#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <cmath>
#include <utility>
#include <list>
#include <iomanip>
using namespace std;

#define bye return 0
#define pb push_back
#define mp make_pair
#define mod(n) (n) % 1000000007
#define e_val 2.718281828

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef pair<lli,lli> plli;
typedef vector<lli> vlli;
typedef map<string,lli> mslli;
typedef map<lli,lli> mlli;
typedef vector<pair<lli,lli> > vplli;

inline bool isPrime(lli n){
	if (n <= 1)  {
		return false;
	}
	if (n <= 3)  {
		return true;
	}

	if (n%2 == 0 || n%3 == 0) {
		return false;
	}
	
	for (int i=5; i*i<=n; i=i+6){
		if (n%i == 0 || n%(i+2) == 0){
			return false;
		}
	}

	return true;
}

inline bool isEven(lli x){
	if(x&1) return false;
	else return true;
}

int main(){
	ios_base::sync_with_stdio(0);
	lli t,n,d,e,f,x,y;
	string a,b,c;
	cin>>a>>b;
	cin>>t;
	lli as = a.size(),bs = b.size();
	while(t--){
		cin>>c;
		lli cs = c.size();
		if(cs > bs){
			cout<<"NO"<<endl;
			continue;
		}
		lli i=0,j=bs-1;
		bool stp = false,qp = false;
		while(i!=j){
			if(b[i] == '*' || b[j] == '*'){
				stp = true;
				break;
			}
			++i;
			--j;
		}
		if(stp == false){
			if(cs < bs){
				cout<<"NO"<<endl;
				continue;
			}
			else if(cs == bs){
				for (i = 0; i < cs; ++i){
					if(b[i] != c[i]){
						if(b[i] == '?'){
							//then check if the letter to be replaced is a good letter in c from a;
							bool fd = false;
							for (int k = 0; k < as; ++k){
								if(a[k] == c[i]){
									fd = true;
									break;
								}
							}
							if(fd == true){
								// this means that letter can be replaced and we can carry on the loop
								continue;
							}
							else{
								cout<<"NO"<<endl;
								qp = true;
								break;
							}
						}
						else{
							cout<<"NO"<<endl;
							qp = true;
							break;
						}
					}
				}
				if(qp == true){
					continue;
				}
				else{
					cout<<"YES"<<endl;
				}
			}

		}
		else if(stp == true){
			// there was one '*' and hence now the length can be same or small;
			//now I check if the length is small
			if(cs < bs){
				for (i = 0; i < cs; ++i){
					if(b[i] != c[i]){
						if(b[i] == '?'){
							//then check if the letter to be replaced is a good letter in c from a;
							bool fd = false;
							for (int k = 0; k < as; ++k){
								if(a[k] == c[i]){
									fd = true;
									break;
								}

							}
							if(fd == true){
								// this means that letter can be replaced and we can carry on the loop
								continue;
							}
							else{
								cout<<"NO"<<endl;
								qp = true;
								break;
							}
						}
						else{
							cout<<"NO"<<endl;
							break;
						}
					}
				}
				if(qp == true){
					continue;
				}
				else{
					cout<<"YES"<<endl;
				}
			}
			else if(cs == bs){
				for (i = 0; i < cs; ++i){
					if(b[i] != c[i]){
						if(b[i] == '?'){
							//then check if the letter to be replaced is a good letter in c from a;
							bool fd = false;
							for (int k = 0; k < as; ++k){
								if(a[k] == c[i]){
									fd = true;
									break;
								}
							}
							if(fd == true){
								// this means that letter can be replaced and we can carry on the loop
								continue;
							}
							else{
								cout<<"NO"<<endl;
								qp = true;
								break;
							}
						}
						else if(b[i] == '*'){
							bool fd = false;
							for (int k = 0; k < as; ++k){
								if(a[k] == c[i]){
									fd = true;
									break;
								}
							}
							if(fd == true){
								// this means that letter can be replaced and we can carry on the loop
								cout<<"NO"<<endl;
								qp = true;
								break;
							}
							else{
								cout<<"YES"<<endl;
								continue;								
							}
						}
						else{
							cout<<"NO"<<endl;
							break;
						}
					}
				}
			}
		}
	}
	bye;
}

