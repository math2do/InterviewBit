/**
 *    author:  math2do
 *    created: 2023-02-21 21:40:10
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
  int exist(vector <string> &mat, string w);
};

int Solution::exist(vector<string> &mat, string w) {
  int n = (int) mat.size();
  int m = (int) mat[0].size();

  int len = (int) w.length();

  vector <int> dx = {1, -1, 0, 0};
  vector <int> dy = {0, 0, 1, -1};

  auto inside = [&](int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
  };

  function<bool(int, int, int)> dfs = [&](int ui, int uj, int i) {
    if (i == len) {
      return true;
    }
    // do the further dfs
    for (int j = 0; j < 4; j++) {
      int vi = ui + dx[j];
      int vj = uj + dy[j];
      if (inside(vi, vj) && mat[vi][vj] == w[i]) {
        if (dfs(vi, vj, i + 1)) {
          return true;
        } 
      } 
    }
    return false;
  };
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (mat[i][j] == w[0]) {
        if (dfs(i, j, 1)) {
          return 1;
        } 
      }
    } 
  }

  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <string> mat(n);
  for (int i = 0; i < n; i++) {
    cin >> mat[i];
  }
  string w;
  cin >> w;
  int ans = Solution().exist(mat, w);
  debug(ans);
  return 0;
}
