/**
 *    author:  math2do
 *    created: 2023-12-06 22:41:02
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
  int solve(int A, vector <vector <int> > & B);
};

int Solution::solve(int A, vector<vector<int> > &B) {
  vector <vector <int> > g(A);
  for (auto &edge : B) {
    int x = edge[0] - 1;
    int y = edge[1] - 1;

    g[x].push_back(y);
    g[y].push_back(x);
  }

  vector <bool> seen(A, false);
  function<bool(int, int)> cyclic = [&](int u, int p) -> bool {
    seen[u] = true;

    for (int v : g[u]) {
      if (v == p) continue;
      
      if (!seen[v]) {
        if (cyclic(v, u)) {
          return true;
        } 
      } else {
        // already visited node, means cyclic
        return true;
      } 
    }
    return false;
  };

  for (int v = 0; v < A; v++) {
    if (!seen[v]) {
      if (cyclic(v, -1)) {
        return 1;
      } 
    } 
  }
  return 0;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  return 0;
}
