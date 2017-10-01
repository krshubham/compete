#include <iostream>
using namespace std;


int days[] = {31, 28, 31, 30, 31, 30, 31, 31,30 31, 30, 31};

class UDdate{
	int day;
	int month;
	int year;
public:
	int operator-(UDdate &);
	friend istream& operator>>(istream&, UDdate&);
	friend ostream& operator<<(ostream&, UDdate&);
};

class med{
	int medid;
	char name[20];
	UDdate today_Date;
	UDdate exp_Date;
public:
	friend istream& opertor>>(istream &, med &);
	friend ostream& operator<<(ostream &, med &);
	UDdate get_Date();
};

istream& UDdate::operator>>(istream &in, UDdate& date){
	in>>date.day>>date.month>>date.year;
	return in;
}

istream& med::operator>>(istream &in, med &m){
	in>>m.medid;
	in>>m.name;
	in>>m.exp_Date;
	return in;
}

int main(){
	int num;
	med e[20];
	UDdate today_Date;
	UDdate exp_date;
	int diff;
	cin>>num;
	for (int i = 0; i < num; ++i){
		cin>>e[i];
	}	
	cin>>today_Date;
	// for (int i = 0; i < num; ++i){
	// 	exp_Date = e[i].get_Date();
	// 	diff  = exp_Date - today_Date;
	// 	if(diff < 31){
	// 		cout<<e[j];
	// 	}
	// }
	return 0;
}
