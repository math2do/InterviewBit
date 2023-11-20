/**
 *    author:  math2do
 *    created: 27.10.2022 00:22:16
**/

#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "lib/debug.h"
#else
#define debug(...) 42
#endif

int Solution::gcd(int a, int b) {
  return b == 0 ? a : gcd(b, a % b);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  
  return 0;
}
