/**
 *    author:  math2do
 *    created: 19.10.2022 19:33:44
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
  int titleToNumber(string s);
};


int Solution::titleToNumber(string s) {
  auto Decode = [&](char ch) {
    return (int) (ch - 'A') + 1;
  };

  int len = (int) s.length();
  int ans = 0;
  int p = 1;
  for (int i = len - 1; i >= 0; i--) {
    int d = Decode(s[i]);
    ans += d * p;
    p *= 26;
  } 
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  int ans = Solution().titleToNumber(s);
  debug(ans);
  return 0;
}
