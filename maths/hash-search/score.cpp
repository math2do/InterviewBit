/**
 *    author:  math2do
 *    created: 19.10.2022 19:23:58
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
  int highestScore(vector <vector <string> > &a);
};

int Solution::highestScore(vector<vector<string> > &a) {
  int n = (int) a.size();
  map <string, vector <int>> mark;
  for (int i = 0; i < n; i++) {
    string name = a[i][0];
    int score = stoi(a[i][1]);
    mark[name].push_back(score);
  } 
  int ans = 0;
  for (auto p : mark) {
    vector <int> vec = p.second;
    int sum = 0;
    for (int v : vec) {
      sum += v;
    }
    int avg = sum / (int) vec.size();
    ans = max(ans, avg);
  } 
  return ans;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <vector <string> > mat(n, vector <string>(2));
  for (int i = 0; i < n; i++) {
    cin >> mat[i][0] >> mat[i][1];
  } 
  int ans = Solution().highestScore(mat);
  debug(ans);
  return 0;
}
