#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin>>n;
    if(n == 1){
        cout<<"impossible"<<endl;
        return 0;
    }
    int num_lines = 2*n-1;
    int num_stars = n;
    int num_spaces = 1;
    for(int _ = 0; _ < n; _++){
        for(int i = 0; i < num_stars; i ++){
            cout<<'*';
        }
        for(int i = 0; i < num_spaces; i++){
            cout<<' ';
        }
        for(int i = 0; i < num_stars; i++){
            cout<<'*';
        }
        cout<<endl;
        num_spaces += 2;
        num_stars--;
    }
    num_stars++;
    num_spaces-=2;
    for(int _ = 0; _ < n-1; _++){
        num_spaces -= 2;
        num_stars++;
        for(int i = 0; i < num_stars; i ++){
            cout<<'*';
        }
        for(int i = 0; i < num_spaces; i++){
            cout<<' ';
        }
        for(int i = 0; i < num_stars; i++){
            cout<<'*';
        }
        cout<<endl;
    }
    return 0;
}