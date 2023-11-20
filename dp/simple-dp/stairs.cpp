/**
 *    author:  math2do
 *    created: 05.11.2022 15:36:53
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
  int climbStairs(int n);
};

int Solution::climbStairs(int n) {
  vector <int> dp(n + 1);
  // dp[i] = no of ways to reach step i
  dp[0] = 0;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i <= n; i++) {
    dp[i] = dp[i - 1] + dp[i - 2];
  } 
  return dp[n];
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = Solution().climbStairs(n);
  debug(ans);
  return 0;
}
