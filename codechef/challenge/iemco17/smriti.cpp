#include <iostream>
#include <map>
#include <algorithm>
using namespace std;

typedef long long ll;
typedef long long int lli;
typedef unsigned long long int ulli; 

map<int, int> palindromeSubStrs(string s){
    map<string, int> m;
    int n = s.size();

    int R[2][n+1];

    
    s = "@" + s + "#";

    for (int j = 0; j <= 1; j++)
    {
        int rp = 0;   // length of 'palindrome radius'
        R[j][0] = 0;

        int i = 1;
        while (i <= n)
        {
            //  Attempt to expand palindrome centered at i
            while (s[i - rp - 1] == s[i + j + rp])
                rp++;  // Incrementing the length of palindromic
                       // radius as and when we find vaid palindrome

            R[j][i] = rp;
            int k = 1;
            while ((R[j][i - k] != rp - k) && (k < rp))
            {
                R[j][i + k] = min(R[j][i - k],rp - k);
                k++;
            }
            rp = max(rp - k,0);
            i += k;
        }
    }

    
    s = s.substr(1, n);

    
    m[string(1, s[0])]=1;
    for (int i = 1; i <= n; i++){
        for (int j = 0; j <= 1; j++)
            for (int rp = R[j][i]; rp > 0; rp--)
               m[s.substr(i - rp - 1, 2 * rp + j)]=1;
           m[string(1, s[i])]=1;
       }
       map<int,int> r;
       map<string, int>::iterator ii;
       for (ii = m.begin(); ii!=m.end(); ++ii){
        r[(*ii).first.size()]++;
    }
    return r;
}


int main(){
    ios_base::sync_with_stdio(0);
    int t,k;
    cin>>t;
    string s;
    map<int, int> m;
    while(t--){
        cin>>s;
        cin>>k;
        if(k == s.size()){
            cout<<"YES"<<endl;
        }
        else{
            map<int, int>::iterator it;
            int f = 0;
            m = palindromeSubStrs(s);
            for (it = m.begin(); it != m.end(); ++it){
                if((*it).second == k){
                    cout<<"YES"<<endl;
                    f = 1;
                    break;
                }
            }
            if(f == 0){
                cout<<"NO"<<endl;
            }
            f = 0;
            m.clear();
        }
    }
    return 0;
}