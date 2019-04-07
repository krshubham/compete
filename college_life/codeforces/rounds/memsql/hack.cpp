#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> a(1001);
	for (int i = 0; i <= 1000; ++i){
		a[i] = i*i;
	}
	int sqr = lower_bound(a.begin(), a.end(),n) - a.begin();
	int tmp = sqr*4;
	int part = sqr*sqr - sqr;
	int kek = (sqr*sqr-n)/sqr;
	cout<<tmp-2*kek;
}
