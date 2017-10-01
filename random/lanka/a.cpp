#include <bits/stdc++.h>
using namespace std;

class complex{
public:
	int real,imaginary;
	friend istream& operator>>(istream &, complex &);
	friend ostream& operator<<(ostream &, complex &);
	int operator [](int);
	complex operator+(complex &);
};

istream& operator>>(istream &in, complex &c){
	in>>c.real>>c.imaginary;
	return in;
}

ostream& operator<<(ostream& out, complex &c){
	out<<c.real<<" "<<c.imaginary<<endl;
	return out;
}

complex complex::operator+(complex &c){
	complex a;
	a.real = this->real + c.real;
	a.imaginary = this->imaginary + c.imaginary;
	return a;
}

int &operator [](int k){
	if(k == 0) return this->real;
	else if(k == 1) return this->imaginary;
}


int main(){
	complex c1,c2,c3,c4,c5,c6;
	// int i,j;
	// //operator>>(cin,c1);
	// cin>>c1;
	// //operator>>(cin,c2);
	// cin>>c2;	
	//c3 = c1.operator+(c2);
	// c3 = c1+c2;
	
	// //operator<<(cout,c3);
	// cout<<c3;
	// cin>>i>>j;
	// try
	// {
	// 	cout<<c1[i]<<endl;
	// 	cout<<c1[j]<<endl;
	// }catch(int k)
	// {
	// 	cout<<"Exception Caught";
	// }
}
