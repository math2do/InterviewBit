/**
 *    author:  math2do
 *    created: 2023-12-13 00:08:55
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
  vector <int> maxone(vector <int> &a, int k);
};

vector<int> Solution::maxone(vector<int> &a, int k) {
  int n = (int) a.size();

  int i = 0;
  int z_cnt = 0;
  int max_len = 0;
  int from = 0;
  
  for (int j = 0; j < n; j++) {
    if (a[j] == 0) {
      z_cnt++;
    }

    // if window is no longer valid, make it valid
    while (z_cnt > k) {
      if (a[i] == 0) {
        z_cnt--;
      }
      i++;
    } 

    if (j - i + 1 > max_len) {
      max_len = j - i + 1;
      from = i;
    } 
  }

  vector <int> ans;
  for (int i = from; i < from + max_len; i++) {
    ans.push_back(i);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector <int> a = {1, 1, 0};
  int k = 2;

  vector <int> ans = Solution().maxone(a, k);
  debug(ans);
  
  return 0;
}
