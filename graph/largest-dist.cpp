#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  int solve(vector <int> &a);
};

class graph {
public:
  struct edge {
    int from;
    int to;
    int cost;
  };
  int n;
  vector <vector <int> > g;
  vector <edge> edges;
  graph(int _n) : n(_n) {
    g.resize(n);
  }

  virtual int add(int from, int to, int cost) = 0;
};

class forest : public graph {
public:
  forest(int _n) : graph(_n) {
  }
  int add(int from, int to, int cost = 1) {
    assert(from >= 0 && from < n && to >= 0 && to < n);
    int id = (int) edges.size();
    assert(id < n - 1);
    g[from].push_back(id);
    g[to].push_back(id);
    edges.push_back({from, to, cost});
    return id;
  } 
};

class dfs_forest : public forest {
public:
  vector <int> d;
  dfs_forest(int _n) : forest(_n) {
  }
  void do_dfs(int u, int p) {
    for (int id : g[u]) {
      int v = edges[id].from ^ edges[id].to ^ u;
      if (v != p) {
        d[v] = d[u] + edges[id].cost;
        do_dfs(v, u);
      } 
    } 
  }
  
  void dfs(int from) {
    d = vector <int>(n, 0);
    d[from] = 0;
    do_dfs(from, -1);
  } 
};

int Solution::solve(vector<int> &a) {
  int n = (int) a.size();
  dfs_forest g(n);
  int root = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] == -1) {
      root = i;
      continue;
    }
    g.add(a[i], i);
  }
  g.dfs(root);

  int from = max_element(g.d.begin(), g.d.end()) - g.d.begin();
  g.dfs(from);
  return *max_element(g.d.begin(), g.d.end());
}

int main() {
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  int ans = Solution().solve(a);
  cout << "ans: " << ans;
  return 0;
} 
