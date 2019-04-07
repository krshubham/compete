class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {
		unordered_map<int,int> mp;
		vector<int> result;
		for (int i = 0; i < numbers.size(); i++) {
			int nos = target - numbers[i];
			if (mp.find(nos) != mp.end()) {
				result.push_back(mp[nos] + 1);
				result.push_back(i + 1);			
				return result;
			}
			mp[numbers[i]] = i;
		}
		return result;
	}
};