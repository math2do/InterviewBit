/**
 *    author:  math2do
 *    created: 13.10.2022 21:17:34
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
  vector <int> solve(vector <int> &a);
};

const int mod = (int) (1e9 + 7);

int mul(int a, int b) {
  long long res = (long long) a * b;
  a = (int) (res % mod);
  if (a < 0) {
    a += mod;
  } 
  return a;
}


vector <int> Solution::solve(vector <int> &a) {
  int n = (int) a.size();
  if (n == 1) {
    return vector <int>(1, 0);
  } 
  vector <int> l(n), r(n);

  // from left
  l[0] = mul(a[0], 1);
  for (int i = 1; i < n; i++) {
    l[i] = mul(a[i], l[i - 1]);    
  }

  // from right
  r[n - 1] = mul(a[n - 1], 1);
  for (int i = n - 2; i >= 0; i--) {
    r[i] = mul(a[i], r[i + 1]);    
  }

  vector <int> ans(n);
  ans[0] = r[1];
  ans[n - 1] = l[n - 2];
  for (int i = 1; i <= n - 2; i++) {
    ans[i] = mul(l[i - 1], r[i + 1]);
  } 
  return ans;
} 

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <int> a = {1, 2, 3, 4};
  vector <int> ans = Solution().solve(a);
  debug(ans);
  return 0;
}
