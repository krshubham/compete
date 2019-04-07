#include <iostream>
#include <ctype.h>
#include <string>
#include <cstring>
#include <locale>
using namespace std;

typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef double dbl;

int main(int argc, char const *argv[])
{
	ios_base::sync_with_stdio(false);
	string a,b;
	cin>>a>>b;
	cout<<strcmp(tolower(a),tolower(b))<<endl;
	return 0;
}