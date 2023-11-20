/**
 *    author:  math2do
 *    created: 2023-02-22 16:48:13
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
  int solve(vector <int> &a);
};

class graph {
public:
  struct edge {
    int from;
    int to;
  };
  int n;
  vector <vector <int> > g;
  vector <edge> edges;
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
    assert(from >= 0 && from < n && to >= 0 && to < n);
    int id = (int) edges.size();
    g[from].push_back(id);
    edges.push_back({from, to});
    return id;
  }
};

int Solution::solve(vector<int> &a) {
  int n = (int) a.size();
  digraph g(n);
  for (int x = 0; x < n; x++) {
    int y = a[x] - 1;
    g.add(y, x);
  }

  vector <bool> seen(g.n, false);
  function <void(int)> dfs = [&](int u) {
    seen[u] = true;
    for (int id : g.g[u]) {
      int v = g.edges[id].to;
      if (!seen[v]) {
        dfs(v);
      } 
    }
  };
  
  int cnt = 0;
  for (int i = 0; i < n; i++) {
    if (!seen[i]) {
      dfs(i);
      cnt++;
    }
  }
  return cnt - 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = Solution().solve(a);
  debug(ans);
  return 0;
}
