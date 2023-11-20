/**
 *    author:  math2do
 *    created: 18.10.2022 20:35:06
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
  vector <string> fizzBuzz(int n);
};

vector<string> Solution::fizzBuzz(int n) {
  vector <string> ans;
  for (int i = 1; i <= n; i++) {
    if (i % 15 == 0) {
      ans.push_back("FizzBuzz");
    } else if (i % 3 == 0) {
      ans.push_back("Fizz");
    } else if (i % 5 == 0) {
      ans.push_back("Buzz");
    } else {
      ans.push_back(to_string(i));
    }  
  }
  return ans; 
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector <string> ans = Solution().fizzBuzz(n);
  debug(ans);  
  return 0;
}
