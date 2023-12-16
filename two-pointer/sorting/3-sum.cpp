/**
 *    author:  math2do
 *    created: 2023-12-12 15:49:13
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
  int threeSumClosest(vector<int> &a, int k);
};

int Solution::threeSumClosest(vector<int> &a, int k) {
  int n = (int) a.size();

  sort(a.begin(), a.end());
  long long dif = (long long) (1e12);
  
  long long ans = 0;
  
  for (int i = 0; i < n - 2; i++) {
    long long A = a[i];
    
    int l = i + 1, h = n - 1;

    while (l + 1 <= h) {
      long long B = a[l];
      long long C = a[h];

      long long rem = k - (A + B + C);
      if (abs(rem) < dif) {
        dif = abs(rem);
        ans = A + B + C;
      }

      if (rem > 0) {
        l++;
      } else {
        h--;
      } 
    }
  }

  return (int) ans;
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  vector <int> a = {5, -2, -1, -10, 10};
  int k = 5;

  int ans = Solution().threeSumClosest(a, k);
  debug(ans);
  return 0;
}
