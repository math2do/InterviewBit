/**
 *    author:  math2do
 *    created: 2023-02-07 19:22:29
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
  int solve(vector <int> &a, int b);
};

int Solution::solve(vector<int> &a, int b) {
  int n = (int) a.size();
  for (int i = 1; i < n; i++) {
    a[i] += a[i - 1];
  }
  int ans = 0;
  for (int i = 0; i < n; i++) {
    // find the index j such that cumulative sum is less than a[i - 1] + b
    int req = b;
    if (i > 0) {
      req += a[i - 1];
    }
    int j = lower_bound(a.begin() + i, a.end(), req) - a.begin();
    if (j > i) {
      j--;
      ans += j - i + 1;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int b;
  cin >> b;
  int ans = Solution().solve(a, b);
  debug(ans);
  return 0;
}
