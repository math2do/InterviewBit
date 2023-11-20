/**
 *    author:  math2do
 *    created: 26.10.2022 23:25:14
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
  void arrange(vector <int> &a);
};


void Solution::arrange(vector<int> &a) {
  int n = (int) a.size(); 
  for (int i = 0; i < n; i++) {
    if (a[i] < 0) {
      continue;
    } 
    int temp = a[i];
    int prev = i;
    int from = a[i];
    int to = i;
    if (from > 0 && temp > 0) {
      while (to != from) {
        // debug(prev, from);
        a[from] = -1 * a[from];
        a[prev] = a[from];
        prev = from;
        from = abs(a[from]);
      } 
      a[prev] = -1 * temp;
    }
  }

  for (int i = 0; i < n; i++) {
    a[i] = abs(a[i]);
  } 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  } 
  Solution().arrange(a);
  debug(a);
  return 0;
}
