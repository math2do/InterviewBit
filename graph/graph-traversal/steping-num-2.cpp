/**
 *    author:  math2do
 *    created: 2023-12-04 23:18:20
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
  vector <int> stepnum(int A, int B);
};

vector<int> Solution::stepnum(int A, int B) {
  vector <int> ans;
  queue <int> q;
  for (int i = 1; i <= 9; i++) {
    q.push(i);
  }
  
  if (0 >= A && 0 <= B) {
    ans.push_back(0);
  }

  while (!q.empty()) {
    int num = q.front(); q.pop();
    if (num >= A && num <= B) {
      ans.push_back(num);
    }

    int d = num % 10;
    if (d - 1 >= 0) {
      int v = num * 10 + (d - 1);
      if (v <= B) {
        q.push(v);
      }
    }

    if (d + 1 <= 9) {
      int v = num * 10 + (d + 1);
      if (v <= B) {
        q.push(v);
      }
    }
  }

  return ans;
  
}


int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  return 0;
}
