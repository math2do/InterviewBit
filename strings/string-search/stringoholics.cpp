/**
 *    author:  math2do
 *    created: 26.11.2022 00:24:38
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
  int solve(vector <string> &a);
};

const int mod = (int) (1e9 + 7); 

vector <int> factors(int n) {
  vector <int> f;
  for (int i = 1; i <= sqrt(n); i++) { 
    if (n % i == 0) {
      if (i * i == n) {
        f.push_back(i);
      } else {
        f.push_back(i);
        f.push_back(n / i);
      }
    } 
  }
  sort(f.begin(), f.end());
  return f; 
}

int gcd(int a, int b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b); 
}

int lcm(int a, int b) {
  int t = a / gcd(a, b);
  long long r = (long long) t * b;
  return (int) (r % mod);
}; 

int Solution::solve(vector<string> &a) {
  auto Solve = [&](string &s) {
    int len = (int) s.length();
    vector <int> f = factors(len);
    debug(s, len, f);
    int i = 0;
    for (i = 0; i < (int) f.size(); i++) {
      bool found = true;
      string w = s.substr(0, f[i]);
      for (int j = 0; j <= len - f[i]; j++) {
        string t = s.substr(j, f[i]);
        if (w != t) {
          found = false;
          break;
        } 
      }
      if (!found) continue;
      break;
    }
    assert(i <= len - 1);
    int ans = 1;
    while (true) {
      int val = ans * (ans + 1) / 2;
      if (val % f[i] == 0) {
        break;
      } 
      ans++;
    }  
    debug(f[i], ans);
    return ans;
  };

  int n = (int) a.size();
  int ans = 1;
  for (int i = 0; i < n; i++) {
    ans = lcm(ans, Solve(a[i]));
  } 
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <string> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  } 
  int ans = Solution().solve(a);
  debug(ans);
  return 0;
}
