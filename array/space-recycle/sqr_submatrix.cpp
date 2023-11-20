#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int solve(vector <vector <int> > &mat, int k);
};

int Solution::solve(vector <vector <int> > &mat, int k) {
  int n = (int) mat.size();
  for (int j = 1; j < n; j++) {
    mat[0][j] = mat[0][j] + mat[0][j - 1];
  }
  for (int i = 1; i < n; i++) {
    mat[i][0] = mat[i][0] + mat[i - 1][0];
  }                                      
  
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < n; j++) {
      mat[i][j] = mat[i][j] + (mat[i - 1][j] + mat[i][j - 1] - mat[i - 1][j - 1]);
    }
  } 

  auto GetSum = [&](int i, int j) {
    int ans = mat[i][j];
    ans -= (i - k >= 0 ? mat[i - k][j] : 0);
    ans -= (j - k >= 0 ? mat[i][j - k] : 0);
    ans += (i - k >= 0 && j - k >= 0 ? mat[i - k][j - k] : 0);
    return ans; 
  };

  int ans = (int) -1e+9;
  for (int i = k - 1; i < n; i++) {
    for (int j = k - 1; j < n; j++) {
      ans = max(ans, GetSum(i, j));
    }
  }

  return ans;
}

int main() {
  return 0;
}