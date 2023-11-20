/**
 *    author:  math2do
 *    created: 18.10.2022 14:53:58
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
  vector <int> primesum(int n);
};

vector<int> Solution::primesum(int n) {
  vector <int> pr;
  vector <bool> is_prime(n + 1, true);
  
  for (int i = 2; i <= sqrt(n); i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= n; j += i) {
        is_prime[j] = false;
      } 
    } 
  } 
  
  pr.push_back(2);
  for (int num = 3; num <= n; num += 2) {
    if (is_prime[num]) {
      pr.push_back(num);
    } 
  }

  // pr has list of primes
  for (int p : pr) {
    int req = n - p;
    if (binary_search(pr.begin(), pr.end(), req)) {
      return vector <int>{p, req};
    } 
  }
  assert(false); 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <int> ans = Solution().primesum(n);
  debug(ans);  
  return 0;
}
