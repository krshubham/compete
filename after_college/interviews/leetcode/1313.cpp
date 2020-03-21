class Solution {
public:
    vector<int> decompressRLElist(vector<int>& nums) {
      vector<int> result;
      for(int i = 0; i < nums.size();) {
        int freq = nums[i++];
        int val = nums[i++];
        for(int j = 0; j < freq; j++) {
          result.push_back(val);
        }
      }
      return result;
    }
};
