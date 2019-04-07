#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

#define gameover return 0
lli n,l;
vector<lli> v;

lli dance(lli a);

void disco(lli hell, lli yeah) {
	lli final = 100000000000007;
	while (yeah - hell >= 3) {
		lli hi = (2*hell + yeah)/3;
		lli bye = (hell + 2*yeah) / 3;
		if (dance(hi) <= dance(bye)){
			yeah = bye--;
		}
		else{
			hell = hi++;			
		} 
	}
	for (int i = hell; i <= yeah; i++){
		final = min(final, dance(i));

	}
	cout<<final<<endl;
}

lli dance(lli drama) {
	lli fin = 0;
	for (int i = 0; i < n; i++){
		fin += abs(v[i] - (drama + i * l));		
	}
	return fin;
}

int main() {
	lli a,b,c;
	lli t;
	cin>>t;
	while(t--){
		cin>>n>>l>>a>>b;
		v.resize(n);	
		for (int i = 0; i < n; ++i){
			cin>>c;
			v[i] = c;
		}
		sort(v.begin(), v.end());
		disco(a, b-n*l);
	}
	gameover;
}