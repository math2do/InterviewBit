/**
 *    author:  math2do
 *    created: 13.10.2022 21:41:34
**/

#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "lib/debug.h"
#else
#define debug(...) 42
#endif

int solve(vector<int> &a) {
  int n = (int) a.size();
  vector <int> pref(a.begin(), a.end());
  for (int i = 1; i < n; i++) {
    pref[i] = max(pref[i], pref[i - 1]);
  } 

  int ans = 1;
  for (int i = 1; i < n; i++) {
    if (a[i] > pref[i - 1]) {
      ans++;
    } 
  } 
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  return 0;
}
