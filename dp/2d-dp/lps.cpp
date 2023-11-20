/**
 *    author:  math2do
 *    created: 03.11.2022 19:36:05
**/

#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "lib/debug.h"
#else
#define debug(...) 42
#endif

class Solution {
public:
  int solve(string s);
};

int Solution::solve(string s) {
  int n = (int) s.length();
  vector <vector <int> > dp(n, vector <int>(n, 0));

  // dp[i][j] = the longest palindromic subsequence in region i....j
  // for len = 1
  for (int i = 0; i < n; i++) {
    dp[i][i] = 1;
  } 
  // for len = 2
  for (int i = 0; i < n - 1; i++) {
    if (s[i] == s[i + 1]) {
      dp[i][i + 1] = 2;
    } else {
      dp[i][i + 1] = 1;
    } 
  } 
  
  // for len = [3, n]
  for (int len = 3; len <= n; len++) {
    for (int i = 0; i <= n - len; i++) {
      int j = i + len - 1; 
      if (s[i] == s[j]) {
        dp[i][j] = 2 + dp[i + 1][j - 1];
      } else {
        dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
      } 
    }
  }
  debug(s);
  for (auto v : dp) {
    debug(v);
  } 

  return dp[0][n - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int ans = Solution().solve(s);
  debug(ans);  
  return 0;
}
