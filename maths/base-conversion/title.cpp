/**
 *    author:  math2do
 *    created: 19.10.2022 19:46:04
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
  string convertToTitle(int col);
};

string Solution::convertToTitle(int col) {
  auto Decode = [&](int v) {
    return (char) ('A' + v);
  };
  string ans;
  while (col > 0) {
    int d = (col - 1) % 26;
    ans.push_back(Decode(d));
    col = (col - 1) / 26;
  } 
  reverse(ans.begin(), ans.end());
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int col;
  cin >> col;
  string ans = Solution().convertToTitle(col);
  debug(ans);
  return 0;
}
