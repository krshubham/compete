#include <iostream>
#include <algorithm>
using namespace std;


typedef long long int lli;
typedef long long ll;
typedef unsigned long long int ulli;
typedef double dbl;


int main(){
    ios_base::sync_with_stdio(0);
    pair<int,int> p[9999];
    int n;
    cin>>n;
    int arr[500][500];
    int barr[500][500];
    int k =1;
    for(int i =0;i<n;i++)
    {
        for(int j =0;j<n;j++){
            cin>>arr[i][j];
            p[arr[i][j]] = make_pair(i,j);
            barr[i][j]=arr[i][j];
        }
    }
    for(int i =0;i<n;i++){
        sort(barr[i],barr[i]+n);
    }
    for(int i =0;i<n;i++){
        for(int j =0;j<n;j++){
            cout<<barr[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}