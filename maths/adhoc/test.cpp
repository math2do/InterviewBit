/**
 *    author:  math2do
 *    created: 19.10.2022 00:04:36
**/

#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "lib/debug.h"
#else
#define debug(...) 42
#endif

const int pinf = numeric_limits<int>::max();
const long long large = (long long) 1e14;

const int mod = (int) (1e9 + 7);

inline int power(int x, int b) {
  long long a = x;
  long long res = 1;
  while (b > 0) {
    if (b & 1) {
      res = res * a;
    }
    b >>= 1;
    a = a * a;
    debug(a, res);
    if (res > large) {
      return pinf;
    }
  }
  if (res > pinf) {
    return pinf;
  }
  return (int) res;
}

/*
int power(int x, int p) {
  long long a = x;
  long long res = 1;
  while (p > 0) {
    if (p % 2 == 1) {
      res = res * a;
    } 
    p >>= 1;
    a = a * a;
    if (res > large || a > large) {
      return pinf;
    } 
  }
  if (res > pinf) {
    return pinf;
  } 
  return (int) res;
}
      */
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int val = power(n, 2);
  debug(val);  
  long long sqr = (long long) n * n;
  debug(sqr);
  return 0;
}
