#include <iostream>
using namespace std;


typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(false);
	string a,b;
	cin>>a>>b;
	if(a == b){
		cout<<-1<<endl;
		return 0;
	}
	a.size() > b.size() ? cout<<a.size() : cout<<b.size();
	return 0;
}
