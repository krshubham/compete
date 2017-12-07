#include <iostream>

using namespace std;

int main(int argc, char const *argv[]){
	long long w, h, res;
	cin >> h >> w;
	if (w < h) {
		res = (w / 2) * 4;
		if (w % 2) ++res;
		else --res;
	} 
	else {
		res = (h / 2) * 4;
		if (h % 2 == 0) res -= 2;
	}
	cout << res << endl;
	return 0;
}