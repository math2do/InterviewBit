/**
 *    author:  math2do
 *    created: 08.11.2022 21:05:35
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
  int anytwo(string s);
};

int Solution::anytwo(string s) {
  int len = (int) s.length();
  if (len < 3) {
    return 0;
  }
  auto Decode = [&](char ch) {
    if (ch >= 'a' && ch <= 'z') {
      return (int) (ch - 'a');
    }
    return (int) (ch - 'A') + 26;
  };
  vector <vector <int> > pos(52);
  for (int i = 0; i < len; i++) {
    pos[Decode(s[i])].push_back(i);
  } 
  for (vector <int> &a : pos) {
    sort(a.rbegin(),  a.rend());
  } 
  for (int i = 0; i <= len - 3; i++) {
    for (int j = i + 1; j <= len - 2; j++) {
      for (int p : pos[Decode(s[i])]) {
        if (p == i) {
          continue;
        }
        // i...p..j or i..j..p
        for (int q : pos[Decode(s[j])]) {
          if (p <= j && q > j) {
            return 1;
          }
          if (p >= j && q > p) {
            return 1;
          } 
        }          
      } 
    }         
  } 

  return 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s;
  while (cin >> s) {
    int ans = Solution().anytwo(s);
    debug(s, ans);  
  }
  return 0;
}
