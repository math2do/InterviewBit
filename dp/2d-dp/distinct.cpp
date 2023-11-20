/**
 *    author:  math2do
 *    created: 08.11.2022 22:00:25
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
  int numDistinct(string a, string b);
};

int Solution::numDistinct(string a, string b) {
  int n = (int) a.length();
  int m = (int) b.length();
  if (m > n) {
    return 0;
  } 
  // dp[i][j] = no of distinct subsequences in a[0: i]
  // that are identical to b[0: j]
  vector <vector <int> > dp(n, vector <int>(m, 0));
  // when b has only last char
  dp[0][0] = b[0] == a[0] ? 1 : 0;
  for (int i = 1; i < n; i++) {
    dp[i][0] = dp[i - 1][0];
    if (a[i] == b[0]) {
      dp[i][0] += 1;
    } 
  }
  // when a has only one character
  
  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i] == b[j]) {
        dp[i][j] += dp[i - 1][j - 1];
      }
      dp[i][j] += dp[i - 1][j]; 
    } 
  } 

  return dp[n - 1][m - 1];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  int ans = Solution().numDistinct(a, b);
  debug(ans);  
  return 0;
}
