#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mp;
        vector<int> result;
        for(int i = 0; i < nums.size(); i++) {
          int required = target - nums[i];
            if(mp.find(required) != mp.end()) {
              result.push_back(mp[required]);
              result.push_back(i);
            }
            else {
              mp[nums[i]] = i;
            }
        }
        return result;
    }
};
