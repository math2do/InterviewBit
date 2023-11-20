/**
 *    author:  math2do
 *    created: 13.11.2022 12:35:38
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
  void solve(vector <vector <char> > &mat);
};

void Solution::solve(vector<vector<char> > &mat) {
  int n = (int) mat.size();
  int m = (int) mat[0].size();

  vector <int> dx = {1, -1, 0, 0};
  vector <int> dy = {0, 0, 1, -1};

  vector <vector <bool> > seen(n, vector <bool>(m, false));

  auto inside = [&](int x, int y) {
    return (x >= 0 && x < n) && (y >= 0 && y < m);
  };

  auto bfs = [&](queue <pair <int, int> > &q) {
    while (!q.empty()) {
      int tt = (int) q.size();
      while (tt--) {
        auto pr = q.front(); q.pop();
        int ui = pr.first;
        int uj = pr.second;
        for (int i = 0; i < 4; i++) {
          int vi = ui + dx[i];
          int vj = uj + dy[i];
          if (inside(vi, vj) && !seen[vi][vj] && mat[vi][vj] == 'O') {
            seen[vi][vj] = true;
            q.push({vi, vj});
          } 
        }
      } 
    } 
  };

  queue <pair <int, int>> q;
  // start from all edge 'O'
  {
    for (int j = 0; j < m; j++) {
      // first row
      int i = 0;
      if (mat[i][j] == 'O') {
        seen[i][j] = true;
        q.push({i, j});
      }
      // last row
      if (n > 1) {
        i = n - 1;
        if (mat[i][j] == 'O') {
          seen[i][j] = true;
          q.push({i, j});
        }
      }
    }

    if (n >= 3) {
      // first column, except top and bottom most
      for (int i = 1; i < n - 1; i++) {
        int j = 0;
        if (mat[i][j] == 'O') {
          seen[i][j] = true;
          q.push({i, j});
        }
        if (m > 1) {
          j = m - 1;
          if (mat[i][j] == 'O') {
            seen[i][j] = true;
            q.push({i, j});
          }
        }
      }
    } 
  }

  bfs(q);
  
  // inner 'O' as still false
  for (int i = 0; i < n; i++) {
    for(int j = 0; j < m; j++) {
      if (!seen[i][j] && mat[i][j] == 'O') {
        mat[i][j] = 'X';
      } 
    } 
  } 
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <vector <char > > mat = {
    {'X', 'X', 'X', 'X'},
    {'X', 'O', 'O', 'X'},
    {'X', 'X', 'O', 'X'},
    {'X', 'O', 'X', 'X'}};
  Solution().solve(mat);
  for (auto row : mat) {
    debug(row);    
  }
  return 0;
}
