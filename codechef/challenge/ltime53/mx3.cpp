#include <iostream>
using namespace std;


long long int str2int(string s){
	long long int res=0,cn=1;
	for(int i=s.length()-1;i>=0;i--){
		res = res + cn*((int)(s[i]-'0'));
		cn=cn*10;
	}
	return res;
}

inline long long int sn(string s){
	long long int sum=0;
	for(int i=0;i<s.length();i++){
		sum = sum + (int)(s[i]-'0');
	}
	return sum;
}

int main(){
	long long int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		long long int num = str2int(s),sum=0,i;
		sum = sn(s);
		if(num%2!=0){
			if(s.length()==1){
				cout<<-1<<endl;
			}
			else{
				if(((int)(s[s.length()-2]-'0')%2)==0){
					sum = sum - (int)(s[s.length()-1]-'0');
					if(sum%3==0){
						for(int j=0;j<(s.length()-1);j++){
							cout<<s[j];
						}
						cout<<endl;
					}
					else{
						cout<<-1<<endl;
					}
				}
				else{
					cout<<-1<<endl;
				}
			}
		}
		else{
			if(sum%3==0){
				cout<<num<<endl;
			}
			else{
				int q = sum%3,fl=0;
				for(i=s.length()-1;i>0;i--){

					if((int)(s[i]-'0')%q==0){
						fl=1;
						cout<<"H"<<i<<endl;
						i = s.length()-i-1;
						for(int pp=0;pp<s.length();pp++){
							if(pp!=i){cout<<s[pp];}
						}
						cout<<endl;
						break;
					}

				}
				if(fl==0){cout<<-1<<endl;}
			}
		}
	}


}