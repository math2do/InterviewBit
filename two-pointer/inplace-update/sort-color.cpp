/**
 *    author:  math2do
 *    created: 2023-12-13 00:39:53
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
  void sortColors(vector <int> &a);
};

int segregate(vector <int> &a, int from, int with) {
  int j = from;
  int n = (int) a.size();

  for (int i = from; i < n; i++) {
    if (a[i] == with) {
      swap(a[j], a[i]);
      j++;
    } 
  }

  return j;
} 

void Solution::sortColors(vector<int> &a) {
  int s = segregate(a, 0, 0);
  segregate(a, s, 1);
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  return 0;
}
