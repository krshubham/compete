#include<bits/stdc++.h>
using namespace std;
 
// Function to print all sub strings
void subString(string s, int n) 
{
    // Pick starting point in outer loop
    // and lengths of different strings for
    // a given starting point
    for (int i = 0; i < n; i++) 
        for (int len = 1; len <= n - i; len++)
            cout << s.substr(i, len) << endl;
}
 
// Driver program to test above function
int main() 
{
    string s = "shubhamdbfnbnewdfbiunwkdfvcqqqqqqduyfhbfdgyiubncvdbuh.uvydguhckuyvghvyfegu.jhvdybcnuhdnelubnvbgh.nvdghneygbgiegkytsgyldsvukeguvnbwghlgfuvebedgberyglugikjhidhasuidiuweufidaweuifbwaeuibfuwiaebfiubaweuibfuwibfiuwaebliufbaewiubfluwbefiewbuifbewubfawgeiufhwaebuifnwabfiuwniufawnbeiufbnwaiuebfiuwaebfiuniaewbfiuaewbuifbuaiwebfiuebariugfawbfiuaewbfgiuabeiufwebfiuwebaiufbweaiubfiauewbfiuewbiufbeuiarbfiusbaiubfkjdshkjhaskjdhfkjdsahfjksadhjkfhsadjkhfuiwehirbweiufbndiuwebdfiuwebfiuwebiufbaiwubfiuwebfiuebwaiBFIUWAEBFIUWAEBIFBIAWEBFIUWAEBFIUWAEBUFHEIUWhfiuwehIOBAFUIUFBIUWBEFIUBAEWIUFBUEIWBKJFBJASKBFJKSABJKDSBAKJFBAKJEBUFEWAIHFWIUAEHIUBFIUWEABFIUWBEWUIBFIUWEBIUWBEIUBFIWUEBFIWEBUIBFEIWUBFIWUEABFIUWEABIFUBWAEIUBFWEIBFIUWAEBIFUWAEBFIUWEABFIUBWAEIUBFWIEUBFWIEUBWEIUBFEWUIBEWIUBWEIUBFIUWEBFIEWBFIUWEI";
    subString(s,s.length());
    return 0;
}