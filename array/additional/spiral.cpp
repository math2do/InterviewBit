/**
 *    author:  math2do
 *    created: 13.10.2022 18:39:45
**/

#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "lib/debug.h"
#else
#define debug(...) 42
#endif


void print(vector <vector <int> > mat) {
  for (vector <int> row : mat) {
    debug(row);
  }
} 

vector <vector <int> > solve(vector<int> &a, int n, int m) {
  int idx = 0;
  vector <vector <int> > mat(n, vector <int>(m));
  int ti = 0, rj = m - 1;
  int bi = n - 1, lj = 0;

  while (true) {
    // top left to top right
    for (int j = lj; j <= rj; j++) {
      mat[ti][j] = a[idx];
      idx++;
    }
    if (idx == n * m) break;
    ti++; 

    // top right to bottom right
    for (int i = ti; i <= bi; i++) {
      mat[i][rj] = a[idx];
      idx++;
    }
    if (idx == n * m) break;
    rj--;

    // bottom right to bottom left
    for (int j = rj; j >= lj; j--) {
      mat[bi][j] = a[idx];
      idx++;
    }
    if (idx == n * m) break;
    bi--;

    // bottom left to top left
    for (int i = bi; i >= ti; i--) {
      mat[i][lj] = a[idx];
      idx++;
    } 
    if (idx == n * m) break;
    lj++;    
  } 
  return mat;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector <int> a = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int n = 1, m = 9;
  vector <vector <int> > mat = solve(a, n, m);
  print(mat); 
  return 0;
}
