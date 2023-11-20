/**
 *    author:  math2do
 *    created: 29.10.2022 00:05:19
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
  int divisibleBy60(vector <int> &a);
};

int Solution::divisibleBy60(vector<int> &a) {
  int n = (int) a.size();
  sort(a.begin(), a.end());
  if (n == 1) {
    return a[0] == 0 ? 1 : 0;
  } else if (n == 2) {
    return (a[0] == 0 && a[1] == 6) ? 1 : 0;
  } 
  if (a[0] != 0) {
    return 0;
  } 
  int cnt = 0;
  for (int i = 1; i < n; i++) {
    if (a[i] % 2 == 0) {
      cnt++;
      break;
    } 
  }
  int sum = 0;
  for (int v : a) {
    sum += v;
  }
  return (sum % 3 == 0 && cnt == 1) ? 1 : 0;
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
  int ans = Solution().divisibleBy60(a);
  debug(ans);
  return 0;
}
