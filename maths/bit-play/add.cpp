/**
 *    author:  math2do
 *    created: 20.10.2022 00:08:05
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
  int addNumbers(int a, int b);
};

int Solution::addNumbers(int a, int b) {
  int c = 0;
  int res = 0;
  for (int sh = 0; sh < 31; sh++) {
    if ((a & (1 << sh)) && (b & (1 << sh))) {
      // both a and b has set bit in position sh
      if (c > 0) {
        res |= (1 << sh);
      }
      c = 1;
    } else if (a & (1 << sh)) {
      if (c > 0) {
        c = 1;
      } else {
        res |= (1 << sh);
        c = 0;
      } 
    } else if (b & (1 << sh)) {
      if (c > 0) {
        c = 1;
      } else {
        res |= (1 << sh);
        c = 0;
      } 
    } else {
      if (c > 0) {
        res |= (1 << sh);        
        c = 0;
      } 
    } 
  }

  return res;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a, b;
  cin >> a >> b;
  int ans = Solution().addNumbers(a, b);
  debug(ans);  
  return 0;
}
