#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(int argc, char const *argv[]){
	ios_base::sync_with_stdio(0);
	lli arr[6][6],max=-11111111;
	for (int i = 0; i < 6; ++i){
		for (int j = 0; j < 6; ++j){
			cin>>arr[i][j];
		}
	}
	for (int i = 1; i < 5; ++i){
		for (int j = 1; j < 5; ++j){
			if(arr[i][j]+arr[i-1][j-1]+arr[i-1][j]+arr[i-1][j+1]+arr[i+1][j-1]+arr[i+1][j]+arr[i+1][j+1] > max){
				max = arr[i][j]+arr[i-1][j-1]+arr[i-1][j]+arr[i-1][j+1]+arr[i+1][j-1]+arr[i+1][j]+arr[i+1][j+1];
			}
		}
	}
	cout<<max<<endl;
	return 0;
}
