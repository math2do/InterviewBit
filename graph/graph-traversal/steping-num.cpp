/**
 *    author:  math2do
 *    created: 2023-02-21 20:44:33
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
  vector <int> stepnum(int from, int to);
};

vector<int> Solution::stepnum(int from, int to) {
  queue <int> q;
  set <int> st;
  for (int d = 1; d <= 9; d++) {
    q.push(d);
    st.insert(d);
  }

  vector <int> ans;
  if (0 >= from && 0 <= to) ans.push_back(0);
  
  while (!q.empty()) {
    int tt = (int) q.size();
    while (tt--) {
      int u = q.front(); q.pop();
      if (u >= from && u <= to) {
        ans.push_back(u);
      }
      int ld = u % 10;
      vector <int> from;
      if (ld - 1 >= 0) from.push_back(ld - 1);
      if (ld + 1 <= 9) from.push_back(ld + 1);
      
      for (int d : from) {
        int v = u * 10 + d;
        if (v > to) continue;
        if (st.find(v) == st.end()) {
          st.insert(v);
          q.push(v);
        }
      } 
    } 
  }
  sort(ans.begin(), ans.end());
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int from, to;
  cin >> from >> to;
  vector <int> ans = Solution().stepnum(from, to);
  debug(ans);
  return 0;
}
