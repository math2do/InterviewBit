/**
 *    author:  math2do
 *    created: 2023-02-20 14:46:27
 **/

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "lib/debug.h"
#else
#define debug(...) 42
#endif

int Solution::solve(vector<int> &a, int k) {
  auto it = upper_bound(a.begin(), a.end(), k);
  return (int) (it - a.begin());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  return 0;
}
