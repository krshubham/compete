#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v;
        for(int i = 0; i < n; i++) {
            int x;
            cin>>x;
            v.push_back(x);
        }
        multiset<int> st;
        int cnt = 1;
        int idx = 0;
        st.insert(v[0]);
        for(int i = 1; i < n; i++) {
            if(v[i] < *st.begin()) {
                cnt++;
            }
            st.insert(v[i]);
            if(i > 4) {
                auto itr = st.find(v[idx++]);
                if(itr != st.end()){
                    st.erase(itr);
                }
            }   
        }
        cout<<cnt<<endl;
    }
    return 0;
}