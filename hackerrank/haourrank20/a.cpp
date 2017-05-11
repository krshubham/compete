#include <iostream>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli;

int main(){
    ios_base::sync_with_stdio(0);
    lli a,b,c,d,ma,mi;
    cin>>a>>b>>c>>d;
    mi = (a>=b) ? a : b;
    ma = (c >= d) ? d : c;
    if(!(ma >= mi)){
        cout<<"NO"<<endl;
        return 0;
    }
    else if(!((ma - mi) >= 0)){
        cout<<"NO"<<endl;
        return 0;
    }
    cout<<"YES"<<endl;
    return 0;
}