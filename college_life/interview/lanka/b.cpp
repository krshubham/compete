#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool No_Sec_Smaller_Flag = false;
template<class T>
T sec_Smaller(T* ele, int n, T e);


template <class T>
T sec_smaller(T*ele, int n, T e){
	T x = e;
	if(ele[1] < e){
		cout<<ele[1]<<endl;
	}
	else{
		No_Sec_Smaller_Flag = true;
		cout<<"No such element exists"<<endl;
	}
	return x;
}

int main(){
	int type,size;
	cin>>type>>size;
	if(type == 0){
		int arr[size];
		int e;
		for (int i = 0; i < size; ++i){
			cin>>arr[i];
		}
		sort(arr,arr+size);
		cin>>e;
		sec_smaller<int>(arr,size,e);
	}
	else{
		string arr[size];
		string e;
		for (int i = 0; i < size; ++i){
			cin>>arr[i];
		}
		sort(arr,arr+size);
		cin>>e;
		sec_smaller<string>(arr,size,e);
	}
	return 0;
}
