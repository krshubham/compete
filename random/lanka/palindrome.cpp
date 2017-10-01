#include <iostream>
using namespace std;

int main(int argc, char const *argv[]){
	string s;
	cin>>s;
	int i,j;
	i = 0;
	j = s.size()-1;
	// while(i<=j){
	// 	if(s[i] == s[j]){
	// 		i++;
	// 		j--;
	// 	}
	// 	else{
	// 		cout<<"Not a palindrome"<<endl;
	// 		return 0;
	// 	}
	// }
	// cout<<"Its a palindrome"<<endl;
	for (int i = 0, j = s.size()-1; i <= j; i++,j--){
		if(s[i] == s[j]){
			i++;
			j--;
		}
		else{
			cout<<"Not a palindrome"<<endl;
			return 0;
		}
	}
	cout<<"Its a palindrome"<<endl;
	return 0;
}
