/**
 *    author:  math2do
 *    created: 13.10.2022 21:38:03
**/

#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "lib/debug.h"
#else
#define debug(...) 42
#endif

vector <int> solve(vector<int> &a) {
  int n = (int) a.size();
  int j = -1;
  for (int i = 0; i < n; i++) {
    if (a[i] > 0) {
      j++;
      swap(a[i], a[j]);
    } 
  }
  return a; 
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <int> a = {1, 0, 2, 0, 0, 0, 4, 5};
  vector <int> ans = solve(a);
  debug(ans);
  return 0;
}
