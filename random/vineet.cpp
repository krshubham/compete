#include <iostream>
using namespace std;


int days[] = {31, 28, 31, 30, 31, 30, 31, 31,30, 31, 30, 31};

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
	friend istream& operator>>(istream &, med &);
	friend ostream& operator<<(ostream &, med &);
	UDdate get_Date();
};

istream& operator>>(istream &in, UDdate& date){
	in>>date.day>>date.month>>date.year;
	return in;
}

istream& operator>>(istream &in, med &m){
	in>>m.medid;
	in>>m.name;
	in>>m.exp_Date;
	return in;
}

UDdate med::get_Date(){
	return this->exp_Date;
}

int UDdate::operator-(UDdate &date){
	int TodayDays = (date.year*365) + (date.month*31) + date.day;
	int expDays = (this->year*365) + (this->month*31) + this->day;
	return expDays - TodayDays;
}

ostream& operator<<(ostream& out, med& m){
	out<<m.medid<<endl<<m.name<<endl;
	return out;
}

int main(){
	int num;
	med e[20];
	UDdate today_Date;
	UDdate exp_Date;
	int diff;
	cin>>num;
	for (int i = 0; i < num; ++i){
		cin>>e[i];
	}	
	cin>>today_Date;
	for (int i = 0; i < num; ++i){
		exp_Date = e[i].get_Date();
		diff  = exp_Date - today_Date;
		if(diff < 31){
			cout<<e[i];
		}
	}
	return 0;
}
