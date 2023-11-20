/**
 *    author:  math2do
 *    created: 05.11.2022 15:44:12
**/

#include <bits/stdc++.h>
 
using namespace std;

class Solution {
public:
  int lis(const vector <int> &a);
};

int Solution::lis(const vector<int> &a) {
  int n = (int) a.size();
  vector <int> dp(n, 1);
  // dp[i] = is the lis when ending at a[i]
  for (int i = 1; i < n; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (a[j] < a[i]) {
        dp[i] = max(dp[i], 1 + dp[j]);
      } 
    } 
  }
  return *max_element(dp.begin(), dp.end());
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  } 
  int ans = Solution().lis(a);
  cout << ans << endl;
  return 0;
}
