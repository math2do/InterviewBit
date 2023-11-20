/**
 *    author:  math2do
 *    created: 11.11.2022 23:05:50
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
  int solve(string a, string b, vector <string> &c);
};

int Solution::solve(string a, string b, vector<string> &c) {
  set <string> dict;
  set <string> seen;
  for (string word : c) {
    dict.insert(word);
  } 
  auto bfs = [&]() -> int {
    seen.insert(a);
    queue <string> q;
    q.push(a);

    int ans = 0;
    while (!q.empty()) {
      int cnt = (int) q.size();
      bool found = false;
      while (cnt--) {
        string u = q.front();
        if (u == b) {
          found = true;
          break;
        } 
        q.pop();
        string v = u;
        for (int i = 0; i < (int) v.length(); i++) {
          char temp = v[i];
          for (int j = 0; j < 26; j++) {
            if ((int) (v[i] - 'a') == j) continue;
            v[i] = (char) (j + 'a');
            auto it = dict.find(v);
            if (it != dict.end()) {
              auto it2 = seen.find(v);
              if (it2 == seen.end()) {
                seen.insert(v);
                q.push(v);
              } 
            } 
          }
          v[i] = temp;
        }
      }
      if (found) {
        break;
      } 
      ans++;
    }
    return ans + 1;  
  };
  return bfs();
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string a, b;
  cin >> a >> b;
  int n;
  cin >> n;
  vector <string> c(n);
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  } 
  int ans = Solution().solve(a, b, c);
  debug(ans);   
  return 0;
}
