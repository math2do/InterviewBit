/**
 *    author:  math2do
 *    created: 13.10.2022 21:55:07
**/

#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "lib/debug.h"
#else
#define debug(...) 42
#endif

vector <vector <int> > solve(vector<vector<int> > &mat) {
  int n = (int) mat.size();

  int lj = 0;
  for (int i = 0; i < n; i++) {
    for (int j = lj; j < n; j++) {
      swap(mat[i][j], mat[j][i]);
    } 
    lj++;
  } 

  return mat;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  return 0;
}
