#include <bits/stdc++.h>
using namespace std;

inline vector<string> split(string str,string sep){
	char* cstr=const_cast<char*>(str.c_str());
	char* current;
	vector<string> arr;
	current=strtok(cstr,sep.c_str());
	while(current!=NULL){
		arr.push_back(current);
		current=strtok(NULL,sep.c_str());
	}
	return arr;
}

int main(int argc, char const *argv[]){
	string fileName,s;
	cin>>fileName;
	ifstream in;
	in.open(fileName.c_str());
	getline(in,s);
	set<string> courses;
	vector<string> v = split(s,"#");
	for (int i = 0; i < v.size(); ++i){
		vector<string> tmp = split(v[i],",");
		for (int j = 0; j < tmp.size(); ++j){
			courses.insert(tmp[j]);
		}
	}
	vector<string> taken;
	set<string>::iterator it = courses.begin();
	for(; it != courses.end(); it++){
		taken.push_back(*it);
	}
	map<string,int> ans;
	for (int p = 0; p < v.size(); ++p){
		// cout<<v[p]<<endl;
		for (int i = 0; i < taken.size()-1; ++i){
			for (int j = i+1; j < taken.size(); ++j){
				string test = taken[i]+" "+taken[j];
				vector<string> tmp = split(v[p],",");
				if(find(tmp.begin(),tmp.end(),taken[i]) != tmp.end() && find(tmp.begin(),tmp.end(),taken[j]) != tmp.end()){
					ans[test]++;
				}
			}
		}
	}
	for (int p = 0; p < v.size(); ++p){
		for (int i = 0; i < taken.size()-2; ++i){
			for (int j = i+1; j < taken.size()-1; ++j){
				for (int k = j+1; k < taken.size(); ++k){
					string test = taken[i]+" "+taken[j] + " " + taken[k];
					vector<string> tmp = split(v[p],",");
					if(find(tmp.begin(),tmp.end(),taken[i]) != tmp.end() && find(tmp.begin(),tmp.end(),taken[j]) != tmp.end() && find(tmp.begin(),tmp.end(),taken[k]) != tmp.end()){
						ans[test]++;
					}	
				}
			}
		}
	}
	// for(auto it = ans.begin(); it != ans.end();it++){
	// 	cout<<it->first<<" "<<it->second<<endl;
	// }
	map<string,int>::iterator iter = ans.begin();
	for (;iter != ans.end();iter++){
		cout<<iter->first<<" "<<iter->second<<endl;
	}
	return 0;
}
