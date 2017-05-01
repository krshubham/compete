#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;



// To return value of a char. For example, 2 is
// returned for '2'.  10 is returned for 'A', 11
// for 'B'
int val(char c){
    if (c >= '0' && c <= '9')
        return (int)c - '0';
    else
        return (int)c - 'A' + 10;
}

// Function to convert a number from given base 'b'
// to decimal
int toDeci(string str, int base)
{
    int len = str.size();
    int power = 1; // Initialize power of base
    int num = 0;  // Initialize result
    int i;

    // Decimal equivalent is str[len-1]*1 +
    // str[len-1]*base + str[len-1]*(base^2) + ...
    for (i = len - 1; i >= 0; i--)
    {
        // A digit in input number must be
        // less than number's base
        if (val(str[i]) >= base){
           return -1;
       }

       num += val(str[i]) * power;
       power = power * base;
   }

   return num;
}

// Driver code
int main(){
    int t,n,a,r,x=0,y;
    string str;
    int base = 4;
    map<int, int> m;
    cin>>t;
    while(t--){
        vector<int> v;
        cin>>n;
        cin>>str;
        a = toDeci(str,base);
        if(a == -1){
            continue;
            x = 1;
        }
        if(x==0){
            for (int i = 1; i <= a; ++i){
                x = pow(2,i);
                r = a % x;
                if(r != a){
                    m[r]++;
                }
                else{
                    break;
                }
            }
            map<int, int>::iterator it;
            for (it = m.begin(); it != m.end(); it++){
                v.push_back((*it).second);
            }
            for (int i = 0; i < v.size(); ++i){
                cout<<v[i];
            }
            m.clear();
        }
        x = 0;
    }
    return 0;
}