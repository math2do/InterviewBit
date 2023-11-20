/**
 *    author:  math2do
 *    created: 15.10.2022 17:30:07
**/

#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "lib/debug.h"
#else
#define debug(...) 42
#endif

int solve(int i, int j) {
  return (i - 1) + (8 - i - 1) + (j - 1) + (8 - j - 1) + 1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  return 0;
}


