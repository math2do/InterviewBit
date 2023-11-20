/**
 *    author:  math2do
 *    created: 13.10.2022 21:46:12
**/

#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "lib/debug.h"
#else
#define debug(...) 42
#endif

int solve(int N) {
  vector <int> sq(N + 1);
  for (int n = 1; n <= N; n++) {
    sq[n] = n * n;
  }

  int ans = 0;
  for (int a = 1; a <= N; a++) {
    for (int b = a; b <= N; b++) {
      int c = a * a + b * b;
      if (binary_search(sq.begin(), sq.end(), c)) {
        ans++;
      }
    } 
  } 

  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N = 13;
  int ans = solve(N);
  debug(ans);
  return 0;
}
