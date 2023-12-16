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

void iota(vector <int> &a) {
  for (int i = 0; i < (int) a.size(); i++) {
    a[i] = i;
  } 
}

//compressed path
class dsu {
public:
  vector <int> p;
  vector <int> r;
  dsu(int n) {
    p.resize(n);
    r.resize(n);
    iota(p);
    fill(r.begin(), r.end(), 0);
  } 

  inline int get(int x) {
    if (x == p[x]) {
      return x;
    }
    return p[x] = get(p[x]);
  }

  inline bool unite(int x, int y) {
    x = get(x);
    y = get(y);
    if (x != y) {
      if (r[y] < r[x]) {
        swap(y, x);
      }
      p[x] = y;
      if (r[x] == r[y]) {
        r[y]++;
      }
      return true;
    }
    return false;
  }  
};

int Solution::solve(int n, vector<vector<int> > &edges) {

  // run kruskal mst algorithm
  int m = (int) edges.size();
  
  vector <int> order(m);
  iota(order);
  sort(order.begin(), order.end(), [&](int i, int j) {
    return edges[i][2] < edges[j][2];  // sort by weight of edges
  });

  dsu d(n);
  int cost = 0;

  for (int i : order) {
    int x = edges[i][0] - 1;
    int y = edges[i][1] - 1;
    int w = edges[i][2];

    if (d.unite(x, y)) {
      // united, take this edge as x & y were not part of same mst set
      cost += w;
    } 
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
