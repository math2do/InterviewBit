/**
 *    author:  math2do
 *    created: 18.10.2022 14:18:36
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
  int solve(int a, int b, int c);
};

int Solution::solve(int a, int b, int c) {
  int total = c - 1 + a;
  return total % b == 0 ? b : total % b;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b, c;
  cin >> a >> b >> c;
  int ans = Solution().solve(a, b, c);
  cout << ans << endl;
  return 0;
}
