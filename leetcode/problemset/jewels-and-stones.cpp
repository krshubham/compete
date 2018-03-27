class Solution {
public:
    int numJewelsInStones(string J, string S) {
  		unordered_map<char, bool> jewel;
  		for (int i = 0; i < J.size(); ++i){
  			jewel[J[i]] = true;
  		}
  		int cnt = 0;
  		for (int i = 0; i < S.size(); ++i){
  			if(jewel[S[i]]){
  				cnt++;
  			}
  		}
  		return cnt;
    }
};