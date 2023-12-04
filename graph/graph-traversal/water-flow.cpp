/**
 *    author:  math2do
 *    created: 2023-02-21 20:18:47
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
  int solve(vector <vector <int>> &mat);
};

int Solution::solve(vector<vector<int> > &mat) {
  int n = (int) mat.size();
  int m = (int) mat[0].size();
  auto inside = [&](int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
  };

  vector <int> dx = {1, -1, 0, 0};
  vector <int> dy = {0, 0, 1, -1};

  vector <vector <bool> > red(n, vector <bool>(m, false));
  vector <vector <bool> > blue(n, vector <bool>(m, false));
  
  auto bfs = [&](queue <pair <int, int> > &q, bool toRedLake) {
    while (!q.empty()) {
      int tt = (int) q.size();
      while (tt--) {
        auto pr = q.front(); q.pop();
        int ui = pr.first;
        int uj = pr.second;
        for (int i = 0; i < 4; i++) {
          int vi = ui + dx[i];
          int vj = uj + dy[i];
          if (toRedLake) {
            if (inside(vi, vj) && !red[vi][vj] && mat[vi][vj] >= mat[ui][uj]) {
              red[vi][vj] = true;
              q.push({vi, vj});
            }
          } else {
            if (inside(vi, vj) && !blue[vi][vj] && mat[vi][vj] >= mat[ui][uj]) {
              blue[vi][vj] = true;
              q.push({vi, vj});
            }
          }
        } 
      }
    } 
  };
  // from red sea
  {
    queue <pair <int, int> > q;
    for (int i = 0, j = m - 1; i < n; i++) {
      red[i][m - 1] = true;
      q.push({i, j});
    }
    if (n > 1) {
      for (int i = n - 1, j = m - 2; j >= 0; j--) {
        red[i][j] = true;
        q.push({i, j});
      }
    }
    bfs(q, true);
  }
  // from blue sea
  {
    queue <pair <int, int> > q;
    for (int i = 0, j = 0; j < m; j++) {
      blue[i][j] = true;
      q.push({i, j});
    }
    if (n > 1) {
      for (int i = 1, j = 0; i < n; i++) {
        blue[i][j] = true;
        q.push({i, j});
      }
    }
    bfs(q, false);
  }

  int ans = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (red[i][j] && blue[i][j]) {
        ans++;
      } 
    } 
  }
  return ans;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector< vector <int> > mat(n, vector <int>(m));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> mat[i][j];
    } 
  } 

  int cnt = Solution().solve(mat);
  debug(cnt);
  return 0;
}
