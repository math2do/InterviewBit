/**
 *    author:  math2do
 *    created: 2023-12-04 23:47:35
 **/

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "Algorithms/debug.h"
#else
#define debug(...) 42
#endif

class Solution {
public:
  void solve(vector <vector <char> > &A);
};

void Solution::solve(vector<vector<char> > &A) {
  int n = (int) A.size();
  int m = (int) A[0].size();

  // idea is to start dfs from 'O' and if this dfs touches edge 'O',
  // then the region remains unbounded

  vector <vector <bool> > seen(n, vector <bool>(m, false));
  auto isEdge = [&](int i, int j) {
    return i == 0 || i == n - 1 || j == 0 || j == m - 1;
  };

  auto isInside = [&](int i, int j) {
    return i >= 0 && i < n && j >= 0 && j < m;
  };

  vector <int> dx = {1, -1, 0, 0};
  vector <int> dy = {0, 0, -1, 1};

  function <void(int, int, bool &, vector <pair <int, int> > &)> dfs = [&](int i, int j, bool &bounded, vector <pair <int, int> > &region) {
    seen[i][j] = true;
    region.push_back({i, j});
    
    if (isEdge(i, j)) {
      bounded = false;
    }

    for (int d = 0; d < 4; d++) {
      int x = i + dx[d];
      int y = j + dy[d];
      if (isInside(x, y) && A[x][y] == 'O' && !seen[x][y]) {
        dfs(x, y, bounded, region);
      } 
    }
  };
  
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (A[i][j] == 'O' && !seen[i][j]) {
        bool bounded = true;
        vector <pair <int, int> > region;
        dfs(i, j, bounded, region);

        if (bounded) {
          for (auto pr : region) {
            A[pr.first][pr.second] = 'X';
          } 
        } 
      } 
    } 
  } 
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  return 0;
}
