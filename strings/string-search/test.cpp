/**
 *    author:  math2do
 *    created: 26.11.2022 02:10:08
**/

#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "lib/debug.h"
#else
#define debug(...) 42
#endif

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  for (int n = 1; n <= 40; n++) {
    debug(n, n * (n + 1) / 2);
  } 
  return 0;
}
