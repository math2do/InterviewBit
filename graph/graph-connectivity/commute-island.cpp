/**
 *    author:  math2do
 *    created: 2023-12-05 22:33:41
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
  int solve(int A, vector<vector<int> > &B);
};

int Solution::solve(int n, vector<vector<int> > &edges) {

  // create a graph as adjacency list 
  vector < vector <pair <int, int> > > g(n);
  for (auto &edge : edges) {
    int x = edge[0] - 1;
    int y = edge[1] - 1;
    int w = edge[2];

    g[x].push_back({y, w});
    g[y].push_back({x, w});
  }

  // run prims algorithm
  priority_queue <pair<int, int>, vector <pair<int, int> >, greater<pair<int, int> > > pq;
  vector <int> dist(n, INT_MAX);
  pq.push({0, 0});
  dist[0] = 0;
  vector <bool> in_mst(n, false);

  while (!pq.empty()) {
    auto pr = pq.top(); pq.pop();
    int u = pr.second;
    in_mst[u] = true;
    
    for (auto &edge : g[u]) {
      int v = edge.first;
      int cost_v = edge.second;

      if (!in_mst[v] && cost_v < dist[v]) {
        dist[v] = cost_v;
        pq.push({dist[v], v});
      } 
    } 
  }

  int cost = 0;
  for (int v : dist) {
    cost += v;
  } 

  return cost;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n = 3;
  vector <vector <int> > edges = {{1, 2, 10}, {2, 3, 5}, {1, 3, 9}};

  int ans = Solution().solve(n, edges);

  debug(ans);
  return 0;
}
