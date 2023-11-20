/**
 *    author:  math2do
 *    created: 03.11.2022 20:02:55
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
  int minDistance(string a, string b);
};

int Solution::minDistance(string a, string b) {
  int n = (int) a.length();
  int m = (int) b.length();
  vector <vector <int> > dp(n, vector <int>(m));

  // dp[i][j] = min steps required to make string a[0:i] and b[0:j] equal
  dp[0][0] = a[0] == b[0] ? 0 : 1;

  // when b has only one character
  for (int i = 1; i < n; i++) {
    if (a[i] == b[0]) {
      dp[i][0] = i;
    } else {
      // delete the character a[i]
      dp[i][0] = 1 + dp[i - 1][0];
    } 
  } 
  // when a has only one character
  for (int j = 1; j < m; j++) {
    if (a[0] == b[j]) {
      dp[0][j] = j;
    } else {
      // insert a character at a[1]
      dp[0][j] = 1 + dp[0][j - 1];
    } 
  } 

  for (int i = 1; i < n; i++) {
    for (int j = 1; j < m; j++) {
      if (a[i] == b[j]) {
        dp[i][j] = dp[i - 1][j - 1];
      } else {
        // delete or character a[i] 
        dp[i][j] = 1 + dp[i - 1][j];
        // insert a character at a[i + 1] so that a[i + 1] == b[j]
        dp[i][j] = min(dp[i][j], 1 + dp[i][j - 1]);
        // replace a character at a[i]
        dp[i][j] = min(dp[i][j], 1 + dp[i - 1][j - 1]);
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
  int ans = Solution().minDistance(a, b);
  debug(ans);  
  return 0;
}
