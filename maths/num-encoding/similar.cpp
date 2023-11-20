/**
 *    author:  math2do
 *    created: 26.10.2022 17:35:26
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

string Solution::solve(string s) {
  int len = (int) s.length();
  if (len == 1) {
    return "-1";
  } 
  int at = len - 2;
  while (at >= 0) {
    if (s[at] < s[at + 1]) {
      break;
    } 
    at--;
  } 
  // the number s is already a maximum no
  if (at == -1) {
    return "-1";
  } 

  // find minium no greater than s[at]
  int pos = at + 1;
  int j = at + 1;
  while (j < len) {
    if (s[j] > s[at] && s[j] <= s[pos]) {
      pos = j;
    } 
    j++;
  } 
  swap(s[at], s[pos]);

  reverse(s.begin() + at + 1, s.end());
  return s;

}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string n;
  cin >> n;
  string ans = Solution().solve(n);
  debug(ans);
  return 0;
}
