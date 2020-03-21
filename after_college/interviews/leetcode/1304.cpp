class Solution {
public:
    vector<int> sumZero(int n) {
      vector<int> result;
        int x = n>>1;
        for(int i = -x; i <= x; i++) {
          if(!(n&1) && i == 0) continue;
          result.push_back(i);
        }
      return result;
    }
};
