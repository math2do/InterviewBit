/**
 *    author:  math2do
 *    created: 2023-02-20 12:03:19
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

int pivotPoint(vector <int> &a) {
  int n = (int) a.size();
  int l = 0, h = n - 1;
  while (h - l > 1) {
    int m = (l + h) / 2;
    if (m - 1 >= l && a[m - 1] < a[m]) {
      l = m;
    } else {
      h = m;
    }
  }
  if (a[l] > a[h]) return l;
  return h;
}

int Solution::solve(vector<int> &a, int k) {
  int p = pivotPoint(a);
  auto it = lower_bound(a.begin(), a.begin() + p + 1, k);
  debug(a, p);
  if (it != a.begin() + p + 1) {
    int at = (int) (it - a.begin());
    if (a[at] == k) {
      return at;
    } 
  }

  // search in a[pivot:n-1]
  int l = p, h = (int) a.size() - 1;
  int ans = -1;
  while (l <= h) {
    int m = (l + h) / 2;
    if (k < a[m]) {
      l = m + 1;
    } else if (k > a[m]) {
      h = m - 1;
    } else {
      ans = m;
      break;
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
