#include  <bits/stdc++.h>
using namespace std;


int solve(vector<int>& nums, int q) {
    int size = nums.size();
    int lo = 0;
    int hi= size - 1;
    while (lo < hi) {
        int mid = lo + (hi-lo)/2;
        if(q >= nums[mid]) {
            lo = mid+1;
        }
        else{
            hi = mid;
        }
    }
    return lo;
}

ostream& operator<<(ostream& out, const vector<int> vec) {
    for(auto it = vec.begin(); it!= vec.end(); it++) {
        out<<*it<<endl;
    }
    return out;
}

int main() {
    int n;
    cin>>n;
    vector<int> nums;
    int x;
    for(int i = 0; i < n; i++) {
        cin>>x;
        nums.push_back(x);
    }
    sort(nums.begin(), nums.end());
    int sums[n];
    sums[0] = nums[0];
    for(int i = 1; i<n;  i++) {
        sums[i]= sums[i-1] + nums[i];
    }
    int q;
    cin>>q;
    int a;
    while(q--) {
        cin>>a;
        int ans = solve(nums, a);
        // cout<<ans<<" "<<sums[ans]<<endl;
    }
    return 0;
}