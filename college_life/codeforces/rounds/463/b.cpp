#include<bits/stdc++.h>
using namespace std;
//#include <fstream>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
#define FILL(a,b) memset((a),(b),sizeof((a)))
#define fast ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define nl printf("\n");
#define myfill(a,b,n) rep(i,0,n){a[i]=b;}
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define rep(i,a,n) for(auto i=a;i<n;i++)
#define fi(it,mp) for(auto it=mp.begin();it!=mp.end();it++)
#define sortv(v) sort(v.begin(),v.end())
#define pb push_back
#define mp(a,b) make_pair(a,b)
#define max3(a,b,c) max(a,max(b,c))
#define min3(a,b,c) min(a,min(b,c))
#define prnt(v) rep(i,0,v.size()){out v[i]<<" ";}
#define fileopen //ifstream in ("/Users/kashishmiglani/Desktop/iCloud Drive (Archive) - 1/Desktop/practice/inputfile") ;
#define fileclose //ofstream printfile("/Users/kashishmiglani/Desktop/op1.txt");
#define MOD 1000000007

typedef long long ll;
typedef string str;
typedef pair<ll,ll> ii;
typedef vector <ii> vii;
typedef vector <char> vc;
typedef vector <string> vs;
typedef map <ll,ll> mii;

const int MAXN = 1e6+5;
int arr[MAXN];
int pr(int i){
    str s=to_string(i);
    int ans=1;
    for(int i=0;i<s.length();i++){
        if(s[i]!='0'){
            ans*=(s[i]-'0');
        }
    }
    return ans;
}
int fin[10][1000001];
ll getsum(int index,int k)
{
    ll sum=0;
    while(index>0)
    {
        sum+=fin[k][index];
        index-=(index&(-index));
    }
    return sum;
}
void update_bit(int curr_ind,int k)
{
    while(curr_ind<=1000000)
    {
        fin[k][curr_ind]++;
        curr_ind += (curr_ind &(-curr_ind));
    }
}
int main()
{
    fast
    ll n,k;
    FILL(arr,0);
    for(int i=0;i<=9;i++)
    {
        arr[i]=i;
    }
    for(int i=10;i<=1e6;i++)
    {
        int prod=pr(i);
        
        arr[i]=arr[prod];
        //cout<<arr[i]<<" ";
    }
   // cout<<arr[200016]<<endl;
    for(int i=1;i<=9;i++)
        FILL(fin[i],0);
    for(int i=1;i<=1000000;i++){
        int a=i;
        int b=arr[i];
        update_bit(a,b);
    }
    //cout<<"he";
    int q;
    cin>>q;
    while(q--){
        int l,r,k;
        cin>>l>>r>>k;
        cout<<getsum(r,k)-getsum(l-1,k)<<endl;
    }
}