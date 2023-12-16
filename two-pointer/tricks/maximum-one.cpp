/**
 *    author:  math2do
 *    created: 2023-12-12 22:46:20
 **/

#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "Algorithms/debug.h"
#else
#define debug(...) 42
#endif

class Solution {
public:
  int solve(vector <int> &a, int k);
};

int Solution::solve(vector <int> &a, int k) {
  int n = (int) a.size();

  int ans = 0;
  int i = 0, j = 0;
  int z_cnt = 0;
  
  while (j < n) {
    // make region i--j invalid by including as much zeros as possible
    while (j < n) {
      z_cnt += a[j] == 0;
      if (z_cnt > k) {
        break;
      } 
      j++;
    }
    

    if (j == n) {
      ans = max(ans, j - i);
      break;
    }
    ans = max(ans, j - i);

    // move i to post zero
    while (i < n) {
      z_cnt -= a[i] == 0;
      if (z_cnt == k){
        break;
      } 
      i++;
    }

    // start new region from i + 1, j + 1
    i++;
    j++;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  // vector <int> a = {0, 0, 0, 0, 0, 1, 1, 1, 1, 1};
  vector <int> a = {9, 0, 1, 0, 1, 0, 0, 0, 1, 1};
  int k = 3;

  int ans = Solution().solve(a, k);
  debug(ans);
  return 0;
}
