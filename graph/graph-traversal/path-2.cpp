/**
 ** author:  math2do
 ** created: 2023-12-04 22:58:05
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
  int solve(int A, vector <vector <int> > &B);
};

int Solution::solve(int A, vector<vector<int> > &B) {
  vector <vector <int>> g(A);
  
  for (auto edge : B) {
    int x = edge[0] - 1;
    int y = edge[1] - 1;
    g[x].push_back(y);
  } 
  
  vector <int> seen(A, false);
  function<bool(int)> dfs = [&](int u) {
    seen[u] = true;
    if (u == A - 1) {
      return 1;
    } 
    for (int v : g[u]) {
      if (!seen[v]) {
        if (dfs(v) == 1) {
          return 1;
        } 
      } 
    }

    return 0;
  };
  
  return dfs(0);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
    
  return 0;
}
