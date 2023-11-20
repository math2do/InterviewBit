/**
 *    author:  math2do
 *    created: 08.11.2022 23:08:01
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
  int isScramble(const string A, const string B);
};

int Solution::isScramble(const string A, const string B) {
  if (A.length() != B.length()) {
    return false;
  } 
  unordered_map <string, bool> dp;
  function <bool(string, string)> solve = [&](string a, string b) {
    if ((int) a.length() == 1) {
      return b == b;
    } 
    if (a == b) {
      return true;
    } 

    string key = a + "*" + b;
    auto it = dp.find(key);
    if (it != dp.end()) {
      return it->second;
    } 

    int n = (int) a.length();
    vector <int> fa(26, 0);
    vector <int> fb(26, 0);
    for (int i = 0; i < n; i++) {
      fa[a[i] - 'a']++;
      fb[b[i] - 'a']++;
    } 
    if (fa != fb) {
      return false;
    }
    bool res = false;
    for (int i = 1; i < n; i++) {
      bool f = solve(a.substr(0, i), b.substr(0, i)) && solve(a.substr(i), b.substr(i));
      bool s = solve(a.substr(0, i), b.substr(n - i)) && solve(a.substr(i), b.substr(0, n - i));
      if (f || s) {
        res = true;
        break;
      } 
    } 
    dp[key] = res;
    return res;
  };
  return solve(A, B);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  bool ans = Solution().isScramble(a, b);
  debug(ans);
  return 0;
}
