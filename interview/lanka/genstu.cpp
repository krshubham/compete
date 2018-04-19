/*
* @Author: krshubham
* @Date:   2018-03-27 14:34:06
* @Last Modified by:   Kumar Shubham
* @Last Modified time: 2018-03-27 14:48:35
*/
#include<iostream>
using namespace std;
#include<string>
//Define this function
template<class T>
T min(T *a,int n);

class student{
string rno,name;
public:
	void get();
	int marks;
	void print();
};

template<class T>
T min(T *a, int n){
	T obj;
	obj = a[0];
	for (int i = 1; i < n; ++i){
		if(a[i].marks < obj.marks){
			obj = a[i];
		}
	}
	return obj;
}

void student::get(){
	string x,y;
	int marks;
	cin>>x>>y>>marks;
	this->rno = x;
	this->name = y;
	this->marks = marks;
}

void student::print(){
	cout<<(this->rno)<<endl;
}




int main()
{
	int a[10],n;
	cin>>n;
	student s[10];
	for(int i=0;i<n;i++)
	s[i].get();
	(min(s,n)).print();
}
