class Solution {
public:
    vector<int> replaceElements(vector<int>& nums) {
      vector<int> result;
      int maxi = -1;
      result.push_back(maxi);
      for(int i = nums.size()-2; i >=0; i--) {
        result.push_back(maxi = max(maxi,nums[i+1]));
      }
      reverse(begin(result), end(result));
      return result;
    }
};
