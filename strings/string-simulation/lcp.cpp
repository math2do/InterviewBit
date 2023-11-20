/**
 *    author:  math2do
 *    created: 26.11.2022 00:00:24
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
  string longestCommonPrefix(vector <string> &a);
};

string Solution::longestCommonPrefix(vector<string> &a) {
  int n = (int) a.size();
  auto solve = [&](string &ans, string &s) {
    string t = "";
    int i = 0;
    while (i < (int) ans.length() && i < (int) s.length()) {
      if (ans[i] != s[i]) {
        break;
      } 
      t.push_back(s[i++]);
    } 
    return t;
  };
  string ans = a[0];
  for (int i = 1; i < n; i++) {
    ans = solve(ans, a[i]);
  } 
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  } 
  string ans = Solution().longestCommonPrefix(a);
  debug(ans);
  return 0;
}
