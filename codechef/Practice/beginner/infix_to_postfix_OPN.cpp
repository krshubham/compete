#include <iostream>
using namespace std;

char stack[400];
int top=-1;
int main(){
	int t;
	cin>>t;
	while(t--){
		string s;
		cin>>s;
		int len=s.size();
		for(int i=0;i<len;i++){
			if(s[i]=='('){
				stack[++top]=s[i];
			}
			else if(s[i]=='+'||s[i]=='-'||s[i]=='/'||s[i]=='*'||s[i]=='%'||s[i]=='^'){
				stack[++top]=s[i];
			}
			else{
				if(s[i]!=')'){
					cout<<s[i];
				}
				else{
					while(1){
						char c=stack[top--];
						if(c=='(')
							break;
						cout<<c;
					}
				}
			}
		}
		while(top!=-1){
			char c=stack[top--];
			if(c!='('){
				cout<<c;
			}
		}
		cout<<endl;
	}
}  