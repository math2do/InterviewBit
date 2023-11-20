/**
 *    author:  math2do
 *    created: 20.10.2022 23:14:17
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
  int reverse(int n);
};

const int pinf = 2147483647; // negative no can go upto -2147483648
//7463847412


int Solution::reverse(int n) {
  int max_d = pinf % 10;
  int max_n = pinf / 10;
  int sign = n < 0 ? -1 : 1;
  n = abs(n);

  int rev_n = 0;
  while (n > 0) {
    int d = n % 10;
    rev_n = rev_n * 10 + d;
    n /= 10;

    // check for overflow in next operation
    if (n > 0) {
      if (rev_n > max_n) {
        return 0;
      } else if (rev_n == max_n) {
        if (n % 10 > max_d && sign == 1) {
          return 0;
        }
        if (n % 10 > max_d + 1 && sign == -1) {
          return 0;
        } 
      } 
    } 
  }
  return sign * rev_n;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  int rev = Solution().reverse(n);
  debug(rev);
  return 0;
}
