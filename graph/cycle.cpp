/**
 *    author:  math2do
 *    created: 12.11.2022 13:11:32
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
  int solve(int n, vector <vector <int> > &mat);
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

bool cyclic(const digraph &g) {
  enum color { white, gray, black };

  vector <color> col(g.n, white);

  function <bool(int)> dfs = [&](int u) -> bool {
    col[u] = gray;
    for (int id : g.g[u]) {
      int v = g.edges[id].from ^ g.edges[id].to ^ u;
      if (col[v] == white) {
        if (dfs(v)) {
          return true;
        } 
      } else if (col[v] == gray) {
        return true;
      }
    } 
    col[u] = black;
    return false; 
  };
  
  for (int u = 0; u < g.n; u++) {
    if (col[u] == white) {
      if (dfs(u)) {
        return true;
      }
    }
  }
  return false; 
  //returns true if digraph is cyclic, else false
} 


int Solution::solve(int n, vector<vector<int> > &edges) {
  digraph g(n);
  for (vector <int> e : edges) {
    g.add(e[0] - 1, e[1] - 1);
  }
  return cyclic(g);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector <vector <int> > edges(m, vector <int>(2));
  for (int i = 0; i < m; i++) {
    cin >> edges[i][0] >> edges[i][1];
  }
  int ans = Solution().solve(n, edges);
  debug(ans);
  return 0;
}
