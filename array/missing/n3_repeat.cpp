/**
 *    author:  math2do
 *    created: 12.10.2022 23:13:35
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
  int repeatedNumber(const vector <int> &a);
};

int Solution::repeatedNumber(const vector <int> &a) {
  int n = (int) a.size();
  const int pinf = numeric_limits<int>::max();
  int x = pinf, y = pinf;
  int cntx = 0, cnty = 0;

  for (int i = 0; i < n; i++) {
    if (a[i] == x) {
      cntx++;
    } else if (a[i] == y) {
      cnty++;
    } else if (cntx == 0) {
      cntx = 1;
      x = a[i];
    } else if (cnty == 0) {
      cnty = 1;
      y = a[i];
    } else {
      cntx--;
      cnty--;
    }    
  }

  cntx = cnty = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == x) {
      cntx++;
    }
    if (a[i] == y) {
      cnty++;
    }

    if (cntx > n / 3) {
      return x;
    }
    if (cnty > n / 3) {
      return y;
    }
  }

  return -1;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <int> a =  { 1, 2, 3, 1, 1 };
  int ans = Solution().repeatedNumber(a);
  cout << ans << endl;
  return 0;
}
