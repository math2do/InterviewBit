/**
 *    author:  math2do
 *    created: 18.10.2022 23:38:24
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
  int isPower(int n);
};

const int pinf = numeric_limits<int>::max();
const long long large = (long long) 1e14;

int Log(int a, int b) {
  return (int) ceil(log(a) / log(b));
}

int power(int x, int p) {
  int LOG = Log(pinf, x);
  if (p > LOG) return pinf;

  long long a = x;
  long long res = 1;
  while (p > 0) {
    if (p % 2 == 1) {
      res = res * a;
    } 
    p >>= 1;
    a = a * a; 
  }
  if (res > pinf) {
    return pinf;
  } 
  return (int) res;
}


int Solution::isPower(int n) {
  if (n == 1) {
    return true;
  }
  auto get = [&](int a) {
    int l = 2, h = 31;
    int p = -1;
    while (l <= h) {
      int m = l + (h - l) / 2;
      int val = power(a, m);
      // debug(a, m, val);
      if (val > n) {
        h = m - 1;
      } else if (val < n) {
        l = m + 1;
      } else {
        p = m;
        break;
      } 
    }
    return p;
  };
  for (int a = 1; a <= (int) sqrt(n); a++) {
    int p = get(a);
    if (p != -1) {
      return true;
    }    
  } 
  return false;
}

//1024000000
//32000

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = Solution().isPower(n);
  debug(ans);  
  return 0;
}
