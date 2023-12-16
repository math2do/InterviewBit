/**
 *    author:  math2do
 *    created: 2023-12-12 23:46:28
 **/

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "Algorithms/debug.h"
#else
#define debug(...) 42
#endif

int Solution::solve(vector<int> &a, int k) {
  int n = (int) a.size();

  map <int, int> cnt;
  int i = 0;
  int ans = 0;
  
  for (int j = 0; j < n; j++) {
    cnt[a[j]]++;

    while (cnt.size() > k) {
      ans++;
      auto it = cnt.find(a[i]);
      if (it->second == 1) {
        cnt.erase(a[i]);
      } else {
        it->second--;
      }
      i++;
    }  
  } 
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  return 0;
}
