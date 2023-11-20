/**
 *    author:  math2do
 *    created: 18.10.2022 20:41:11
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
  int solve(int n);
};

// 0 1   3     6       10             15                21  28 36  45
// 0 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21

// 1 + 2 - 3 + 5 + 6 + 8 + 9 = 42

int Solution::solve(int n) {
  n = abs(n);
  if (n <= 1) {
    return n;
  } 
  auto Get = [&]() {
    int l = 1, h = (int) 1e9;
    int pos = 0;
    while (l <= h) {
      int m = l + (h - l) / 2;
      long long res = (long long) m * (m + 1);
      if (res >= 2 * n) {
        pos = m;
        h = m - 1;
      } else {
        l = m + 1;
      } 
    }
    return pos; 
  };
  int pos = Get();
  debug(pos);
  if (pos * (pos + 1) == 2 * n) {
    return pos;
  }

  int new_n = pos * (pos + 1) / 2;
  if (n % 2 == 1) {
    if (new_n % 2 == 0) {
      if ((pos + 1) % 2 == 1) {
        return pos + 1;
      } else {
        return pos + 2;
      } 
    } else {
      return pos;
    } 
  } else {
    if (new_n % 2 == 1) {
      if ((pos + 1) % 2 == 1) {
        return pos + 1;
      } else {
        return pos + 2;
      }
    } else {
      return pos;
    } 
  } 
  assert(false);
  return -1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = Solution().solve(n);
  debug(ans);
  return 0;
}
