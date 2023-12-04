/**
 *    author:  math2do
 *    created: 11.11.2022 22:36:59
**/

#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "lib/debug.h"
#else
#define debug(...) 42
#endif

class graph {
public:
  struct edge {
    int from;
    int to;
  };
  int n;
  vector <edge> edges;
  vector <vector <int> > g;

  graph(int _n) : n(_n) {
    g.resize(n);
  }
  virtual int add(int from, int to) = 0;
};

class digraph : public graph {
public:
  digraph(int _n) : graph(_n) {
  }
  
  int add(int from, int to) {
    assert(from >= 0 && from <= n - 1 && to >= 0 && to <= n - 1);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to});
    return id;
  }
};

class Solution {
public:
  int solve(int a, vector<vector<int> > &edges);  
};

int Solution::solve(int a, vector<vector<int> > &edges) {
  int n = 0;
  for (auto edge : edges) {
    n = max(n, edge[0]);
    n = max(n, edge[1]);
  } 
  digraph g(n);
  for (auto edge : edges) {
    g.add(edge[0] - 1, edge[1] - 1); // path from edges[i][0] -- > edges[i][1]
  }
  
  vector <bool> seen(g.n, false);
  function <bool(int)> dfs = [&](int u) {
    seen[u] = true;
    if (u == a - 1) {
      return true;
    }
    for (int id : g.g[u]) {
      int v = g.edges[id].to;
      if (!seen[v]) {
        if (dfs(v)) {
          return true;
        } 
      } 
    }
    return false; 
  };
  return dfs(0) ? 1 : 0;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int a;
  cin >> a;
  int m;
  cin >> m;
  vector <vector <int> > edges(m, vector <int>(2));
  for (int i = 0; i < m; i++) {
    cin >> edges[i][0] >> edges[i][1];
  } 
  int ans = Solution().solve(a, edges);
  debug(ans);
  return 0;
}
