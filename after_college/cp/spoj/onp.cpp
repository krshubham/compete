#include <bits/stdc++.h>
using namespace std;

int priority(char);

string solve(string expression) {
    stack<char> st;
    string result;
    for(char c:expression) {
        if(isalpha(c)) {
            result += c;
        }
        else if(c == '(') {
            st.push('(');
        }
        else if(c == ')') {
            while(st.top() != '(') {
                result += st.top();
                st.pop();
            }
            st.pop();
        }
        else {
            if(priority(c) < priority(st.top())) {
                while(priority(st.top() < priority(c))) {
                    result += st.top();
                    st.pop();
                }
                st.push(c);
            }
            else {
                st.push(c);
            }
        }
    }
    while(st.size() != 0) {
        result += st.top();
        st.pop();
    }
    return result;
}

inline int priority(char c) {
    if(c == '^') {
        return '5';
    }
    if(c == '/') {
        return '4';
    }
    if(c == '*') {
        return 3;
    }
    if(c == '+') {
        return 1;
    }
    if(c == '-') {
        return 2;
    }
    return -1;
}

int main() {
    int t;
    cin>>t;
    string s;
    while(t--) {
        cin>>s;
        cout<<solve(s)<<endl;
    }
    return 0;
}