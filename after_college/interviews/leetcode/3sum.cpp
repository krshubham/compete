/*
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      unordered_map<int,int> mp;
      for(int i = 0; i < nums.size(); i++) {
        for(int j = i+1; j < nums.size(); j++) {
          int required = -(nums[i] + nums[j]);
          if(mp.find(required) != mp.end()) {
            
          }
        }
      }
    }
};
