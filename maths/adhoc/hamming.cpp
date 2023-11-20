/**
 *    author:  math2do
 *    created: 18.10.2022 17:52:15
**/

#include <bits/stdc++.h>
 
using namespace std;
 
#ifdef LOCAL
#include "lib/debug.h"
#else
#define debug(...) 42
#endif


class Solution {
public:
  int hammingDistance(const vector <int> &a);
};

const int mod = (int) (1e9 + 7);

inline int mul(int a, int b) {
  long long res = (long long) a * b;
  a = (int) (res % mod);
  if (a < 0) {
    a += mod;
  } 
  return a;
}

inline void add(int &a, int b) {
  a = a + b;
  if (a >= mod) {
    a -= mod;
  }
}

int Solution::hammingDistance(const vector<int> &a) {
  int n = (int) a.size();
  vector <int> fre(32, 0);
  for (int sh = 0; sh < 32; sh++) {
    for (int i = 0; i < n; i++) {
      if (a[i] & (1 << sh)) {
        fre[sh]++;
      } 
    } 
  }

  // fre[i], the no. of elements with setbit at position i
  int ans = 0;
  for (int sh = 0; sh < 32; sh++) {
    if (fre[sh] > 0) {
      int rem = n - fre[sh];
      int ret = mul(fre[sh], rem);
      add(ans, ret);
    } 
  } 
  return mul(ans, 2);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  } 
  int ans = Solution().hammingDistance(a);
  debug(ans);
  return 0;
}
