/**
 *    author:  math2do
 *    created: 13.10.2022 18:35:54
**/

#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "lib/debug.h"
#else
#define debug(...) 42
#endif

int solve(vector<int> &A, vector<int> &B, int C) {
  int cnta = 0, cntb = 0;
  for (int v : A) {
    if (v > C) {
      cnta++;
    } 
  }
  for (int v : B) {
    if (v < C) {
      cntb++;
    } 
  }

  return max(cnta, cntb);
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  return 0;
}
