#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findNumbers(vector<int>& nums) {
      int count = 0;
      for(int i = 0; i < nums.size(); i++) {
        count += !(to_string(nums[i]).size()&1);
      }
      return count;
    }
};


int main(int argc, char const *argv[]) {
  Solution sol;
  vector<int> nums;
  nums.push_back(12);
  nums.push_back(345);
  nums.push_back(2);
  nums.push_back(6);
  nums.push_back(7896);
  cout<<sol.findNumbers(nums)<<endl;
  return 0;
}
