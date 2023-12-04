/**
 *    author:  math2do
 *    created: 2023-02-22 07:50:39
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
  int solve(vector <int> &b, vector <vector <int>> &edges, int c);
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

class forest : public graph {
public:
  forest(int _n) : graph(_n) {
  }
  int add(int from, int to) {
    assert(from >= 0 && from < n && to >= 0 && to < n);
    int id = (int) edges.size();
    assert(id < n - 1);
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to});
    return id;
  } 
};

int Solution::solve(vector<int> &b, vector<vector<int> > &edges, int c) {
  int n = (int) edges.size() + 1;
  if (n == 1) {
    return b[0] <= c;
  }
  
  forest g(n);
  for (int i = 0; i < n - 1; i++) {
    int x = edges[i][0] - 1;
    int y = edges[i][1] - 1;
    g.add(x, y);
  }
  vector <int> total(n, 0);
  function<void(int, int, int)> dfs = [&](int u, int p, int good) {
    total[u] = b[u] + good;
    
    for (int id : g.g[u]) {
      int v = g.edges[id].from ^ g.edges[id].to ^ u;
      if (v != p) {
        dfs(v, u, good + b[u]);
      } 
    } 
  };

  dfs(0, -1, 0);

  int ans = 0;
  for (int i = 1; i < n; i++) {
    if ((int) g.g[i].size() == 1 && total[i] <= c) {
      ans++;
    } 
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> b(n);
  for (int i = 0; i < n; i++) {
    cin >> b[i];
  }
  vector <vector <int>> edges(n - 1, vector <int>(2));
  for (int i = 0; i < n - 1; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }
  int c;
  cin >> c;
  int ans = Solution().solve(b, edges, c);
  debug(ans);
  return 0;
}
