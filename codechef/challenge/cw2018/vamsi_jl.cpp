#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 101010;
int a, b, c, d, f[MAXN],t;
int main(){
	cin>>t;
	while(t--){
		bool fl = 0;
		memset(f, 0, sizeof(f));
		cin>>b>>c>>a>>d;
		for(int i = b; i < MAXN; i += a)
			f[i] |= 1;
		for(int i = d; i < MAXN; i += c)
			f[i] |= 2;
		for(int i = 0; i < MAXN; i++){
			if(f[i] == 3){
				printf("YES\n", i);
				fl = 1;
				break;
			}
		}
		if(fl == 0){
			printf("NO\n");
		}
	}
	return 0;
}