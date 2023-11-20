/**
 *    author:  math2do
 *    created: 20.10.2022 00:21:01
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
  int isPalindrome(int n);
};

int Solution::isPalindrome(int n) {
  if (n < 0) {
    return 0;
  } 
  int temp = n;
  int rev = 0;
  while (n > 0) {
    int d = n % 10;
    rev = rev * 10 + d;
    n /= 10;
  }   
  return rev == temp;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int ans = Solution().isPalindrome(n);
  debug(ans);    
  return 0;
}
