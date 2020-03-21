class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
      int k = 0;
      for(int i = 0; i < A.size(); i++) {
        if(A[i] > 0) {
          k = i;
          break;
        }
      }

      int i = k-1;
      int j = k;
      vector<int> temp;
      while(i >= 0 && j < n) {
        if(arr[i]*arr[i] < arr[j*arr[j]]) {
          temp.push_back(arr[i]*arr[i]);
          i--;
        }
        else {
          temp.push_back(arr[j]*arr[j]);
          j++;
        }
      }
      while(i >= 0) {
        temp.push_back(arr[i]*arr[i]);
        i--;
      }

      while(j < n) {
        temp.push_back(arr[j] * arr[j]);
        j++;
      }
      return temp;
    }
};
