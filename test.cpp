#include<iostream>
using namespace std;
#include<string.h>
class text
{
protected:
	char str[100];
public:

	text(){}

	text(char*);
	void get();
	int length();
	int split(char delimit,char a[][20]);
};


int main(){
	string s;
	cin>>s;
	int c = 0;
	for (int i = 0; i < s.size(); ++i){
		if(s[i] == '\0'){
			cout<<"Invalid input"<<endl;
			return 0;
		}
		if(s[i] == ','){
			c++;
		}		
		if(s[i] == '$'){
			if(c != 2){
				cout<<"Invalid input"<<endl;
				return 0;
			}
			c = 0;
		}
	}
	for (int i = 0; i < s.size(); ++i){
		if(s[i] == ',' || s[i] == '$'){
			cout<<endl;
			continue;
		}
		cout<<s[i];
	}
	cout<<endl;
}