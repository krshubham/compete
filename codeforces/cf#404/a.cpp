#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;


int main(int argc, char const *argv[]){
	lli t;
	cin>>t;
	lli sum = 0;
	while(t--){
		string a;
		cin>>a;
		if(a== "Tetrahedron")
			sum+=4;
		if(a == "Cube")
			sum+= 6;
		if(a=="Octahedron")
			sum +=8;
		if(a=="Dodecahedron")
			sum+=12;
		if(a=="Icosahedron")
			sum+=20;
	}	
	cout<<sum<<endl;
	return 0;
}
