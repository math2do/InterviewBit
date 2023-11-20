/**
 *    author:  math2do
 *    created: 21.10.2022 17:21:39
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
  string solve(string s);
};
// 3874277931 9 8650286024
// 3874277931 9 1397724983
// 184963788291359 953192887369481
// 184963788291359 953192887369481

string Solution::solve(string s) {
  int len = (int) s.length();
  int m = len / 2;
  bool allNine = true;
  int even = len % 2 == 0 ? 1 : 0;
  for (int i = 0; i <= m - even; i++) {
    if (s[i] != '9') {
      allNine = false;
      break;
    } 
  }

  if (allNine) {
    // solve specifically for all 9s
    string ans = "1";
    for (int i = 0; i < len - 1; i++) {
      ans.push_back('0');
    } 
    ans.push_back('1');
    return ans;
  }  

  string ans = s;
  for (int i = 0; i < m; i++) {
    ans[len - i - 1] = ans[i];
  }
  debug("palin", ans); 
  for (int i = 0; i < len; i++) {
    if (ans[i] == s[i]) {
      continue;
    } else if (ans[i] > s[i]) {
      return ans;
    } else {
      break;
    } 
  }

  // change one character
  int from = 0;
  for (int i = m - even; i >= 0; i--) {
    if (ans[i] != '9') {
      ans[i] = ans[len - i - 1] = (char) (ans[i] + 1);
      from = i;
      break;
    }
  }
  for (int i = from + 1; i < len - from - 1; i++) {
    ans[i] = '0';
  } 

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  cin >> s;
  string ans = Solution().solve(s);
  debug(ans);
  return 0;
}
