#include <bits/stdc++.h>
using namespace std;



class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
      int start = 0;
      for(int i = 0; i < nums.size(); i++) {
          if((nums[i]%2) == 0) {
            int temp = nums[start];
            nums[start] = nums[i];
            nums[i] = temp;
            start++;
          }
      }
      return nums;
    }
};


int main() {
  Solution solution;
  vector<int> nums {1,2,2,2};
  solution.sortArrayByParity(nums);
  for(auto& num: nums) {
    cout<<num<<" ";
  }
  cout<<endl;
  return 0;
}
