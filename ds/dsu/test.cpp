// C/C++ program to get maximum xor value
// of two numbers in a range
#include <bits/stdc++.h>
typedef unsigned long long int ulli;
using namespace std;
 
// method to get maximum xor value in range [L, R]
ulli maxXORInRange(ulli L, ulli R)
{
    // get xor of limits
    ulli LXR = L ^ R;
 
    //  loop to get msb position of L^R
    ulli msbPos = 0;
    while (LXR)
    {
        msbPos++;
        LXR >>= 1;
    }
 
    // construct result by adding 1,
    // msbPos times
    ulli maxXOR = 0;
    ulli two = 1;
    while (msbPos--)
    {
        maxXOR += two;
        two <<= 1;
    }
 
    return maxXOR;
}
 
//  Driver code to test above methods
int main(){
    // ulli L = 1000000000;
    // ulli R = 20000000000;
    ulli L,R;
    cin>>L>>R;
    cout << maxXORInRange(L, R) << endl;
    return 0;
}