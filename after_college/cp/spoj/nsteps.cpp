#include <bits/stdc++.h>
using namespace std;

int main() {
    int t,x,y;
	string no = "No Number";
    cin>>t;
    while(t--) {
        cin>>x>>y;
		if(x == 0)  {
			if(y == 0) {
				cout<<0<<endl;
			}
			else {
				cout<<no<<endl;
			}
			continue;
		}
		if(x == 1) {
			if(y == 1) {
				cout<<1<<endl;
			}
			else {
				cout<<no<<endl;
			}
			continue;
		}
        if(x&1) {
			if(y == x-2) {
				cout<<x+y-1<<endl;
			}
			else if(y == x) {
				cout<<x+y-1<<endl;
			}
			else {
				cout<<no<<endl;
			}
        }
        else {
            if(y == x-2) {
				cout<<x+y<<endl;
			}
			else if(y == x) {
				cout<<x+y<<endl;
			}
			else {
				cout<<no<<endl;
			}
        }
    }
    return 0;
}