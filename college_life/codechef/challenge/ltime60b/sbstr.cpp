#include <iostream>
# include <unordered_set>
using namespace std;
inline bool check(string s,int start,int end,int *hash,int k){
	int count=0,i,j,index=-1;
	for(i=0;i<26;i++){
		if(hash[i]!=0){
			if(index == -1)
			index=i;
			else{
				if(hash[index]!=hash[i])
				return false;
			}
			count++;
		}
	}
	if(count<k){
	    return false;
    }
	for(i=start;i<=end;i+=count){
		unordered_set <int> se;
		for(j=i;j<i+count;j++)
		if(se.find(s[j])!=se.end()){
		    return false;
        }
		else{
		    se.insert(s[j]);
        }
	}
	return true;
}
int main() {
	int t;
	cin>>t;
	while(t--){
		string s;
		int k;
		cin>>s>>k;
		int i,j,count=0;
		int n=s.length();
		for(i=0;i<n;i++){
			int hash[26]={0};
			for(j=i;j<n;j++){
				hash[s[j]-'a']++;
				if(check(s,i,j,hash,k)){
					for(int x=i;x<=j;x++)
					cout<<s[x];
					cout<<endl;
					count++;
				}
			}
		}
		cout<<count<<endl;
	}
	return 0;
}