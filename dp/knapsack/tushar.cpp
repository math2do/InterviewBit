/**
 *    author:  math2do
 *    created: 03.11.2022 22:26:30
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
  int solve(const vector<int> &frnd, const vector<int> &cap, const vector<int> &cost);
};

int Solution::solve(const vector<int> &frnd, const vector<int> &cap, const vector<int> &cost) {
  int m = (int) cap.size();

  int upto = *max_element(frnd.begin(), frnd.end());
  const int pinf = numeric_limits<int>::max();
  vector <vector <int> > dp(upto + 1, vector <int>(m, pinf));
  fill(dp[0].begin(), dp[0].end(), 0);

  for (int w = 1; w <= upto; w++) {
    for (int i = 0; i < m; i++) {
      if (cap[i] <= w && dp[w - cap[i]][i] != pinf) {
        dp[w][i] = min(dp[w][i], cost[i] + dp[w - cap[i]][i]);
      }  
      // excluding
      if (i > 0) {
        dp[w][i] = min(dp[w][i], dp[w][i - 1]);
      }
    }
  }

  int ans = 0;
  for (int fc : frnd) {
    ans += dp[fc][m - 1];
  } 
  return ans;
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> frnd(n);
  for (int i = 0; i < n; i++) {
    cin >> frnd[i];
  }

  int m;
  cin >> m;
  vector <int> cap(m);
  for (int i = 0; i < m; i++) {
    cin >> cap[i];
  } 

  vector <int> cost(m);
  for (int i = 0; i < m; i++) {
    cin >> cost[i];
  }

  int ans = Solution().solve(frnd, cap, cost);
  debug(ans);
  return 0;
}
