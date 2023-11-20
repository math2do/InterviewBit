/**
 *    author:  math2do
 *    created: 03.11.2022 19:15:35
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
  int solve(string a, string b);
};

int Solution::solve(string a, string b) {
  int n = (int) a.length();
  int m = (int) b.length();

  // dp[i][j] = the longest common subsequence when 0...i and 0...j characters
  // of string a and b are considered

  vector <vector <int> > dp(n, vector <int>(m, 0));

  // base case 1
  dp[0][0] = a[0] == b[0] ? 1 : 0;
  for (int i = 1; i < n; i++) {
    if (a[i] == b[0]) {
      dp[i][0] = 1;
    } else {
      dp[i][0] = dp[i - 1][0];
    } 
  } 

  // base case 2
  for (int j = 1; j < m; j++) {
    if (a[0] == b[j]) {
      dp[0][j] = 1;
    } else { 
      dp[0][j] = dp[0][j - 1];
    }
  }

  // solve for remaining
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i] == b[j]) {
        dp[i][j] = 1 + dp[i - 1][j - 1];
      } else {
        dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
      } 
    }
  }

  return dp[n - 1][m - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  int ans = Solution().solve(a, b);
  debug(ans);  
  return 0;
}
