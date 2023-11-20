/**
 *    author:  math2do
 *    created: 05.11.2022 15:12:12
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
  int solve(vector <int> &v, vector <int> &w, int c);
};

int Solution::solve(vector<int> &v, vector<int> &w, int c) {
  int n = (int) v.size();
  // dp[i][j] = maximum value of weights that can be picked from [0...j] by knapsack of capacity i

  vector <vector <int> > dp(c + 1, vector <int>(n, 0));
  for (int wg = 1; wg <= c; wg++) {
    for (int i = 0; i < n; i++) {
      if (w[i] <= wg) {
        dp[wg][i] = max(dp[wg][i], v[i] + (i > 0 ? dp[wg - w[i]][i - 1] : 0)); 
      }
      // don't take it
      dp[wg][i] = max(dp[wg][i], (i > 0 ? dp[wg][i - 1] : 0));
    } 
  }
  return dp[c][n - 1]; 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> v(n), w(n);
  for (int i = 0; i < n; i++) {
    cin >> v[i];
  } 
  for (int i = 0; i < n; i++) {
    cin >> w[i];
  }
  int c;
  cin >> c;
  int ans = Solution().solve(v, w, c);
  debug(ans);
  return 0;
}
