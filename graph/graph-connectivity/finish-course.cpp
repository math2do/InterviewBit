/**
 *    author:  math2do
 *    created: 2023-12-06 22:22:59
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
  int solve(int A, vector <int> &B, vector <int> &C);
};

enum color { black, grey, white };

int Solution::solve(int A, vector <int> &B, vector <int> &C) {

  assert(B.size() == C.size());
  vector <vector <int> > g(A);
  // make a graph from dependency array
  for (int i = 0; i < (int) B.size(); i++) {
    int x = B[i] - 1;
    int y = C[i] - 1;
    g[x].push_back(y);
  }

  vector <color> col(A, black);

  function<bool(int)> cyclic = [&](int u) -> bool {
    col[u] = grey;
    
    for (int v : g[u]) {
      if (col[v] == black) {
        if (cyclic(v)) {
          return true;
        } 
      } else if (col[v] == grey) {
        return true;
      } 
    }
    col[u] = white;

    return false;
  };

  for (int i = 0; i < A; i++) {
    if (col[i] != white) {
      if (cyclic(i)) {
        return 0;
      } 
    } 
  }

  return 1;
} 

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  return 0;
}
