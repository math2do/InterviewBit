/**
 *    author:  math2do
 *    created: 2023-12-12 15:44:51
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

int Solution::solve(vector<int> &a, int k) {
  int n = (int) a.size();
  set <int> st;
  for (int i = 0; i < n; i++) {
    auto it = st.find(a[i]);
    if (it != st.end()) {
      return 1;
    }
    st.insert(a[i] + k);
    st.insert(a[i] - k);
  }
  return 0;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  return 0;
}
