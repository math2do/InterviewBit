/**
 *    author:  math2do
 *    created: 2023-02-20 14:55:49
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
  int solve(vector <int> &a, int k);
};

int Solution::solve(vector<int> &a, int k) {
  int n = (int) a.size();
  int l = *min_element(a.begin(), a.end());
  int h = *max_element(a.begin(), a.end());

  auto cutLength = [&](int at) {
    int len = 0;
    for (int i = 0; i < n; i++) {
      if (a[i] >= at) {
        len += a[i] - at;
        if (len >= k) {
          break;
        } 
      } 
    }
    return len;
  };

  int ans = 0;
  while (l <= h) {
    int m = (l + h) / 2;
    int len = cutLength(m);
    if (len >= k) {
      ans = m;
      l = m + 1;
    } else {
      h = m - 1;
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
  int k;
  cin >> k;
  int ans = Solution().solve(a, k);
  debug(ans);
  return 0;
}
