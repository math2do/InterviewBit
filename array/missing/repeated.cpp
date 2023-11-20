#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
  vector<int> repeatedNumber(const vector<int> &a);
};

vector<int> Solution::repeatedNumber(const vector<int> &a) {
  int xy = 0;
  int n = (int) a.size();
  for (int i = 0; i < n; i++) {
    xy ^= a[i];
    xy ^= (i + 1);
  }

  int pivot = xy & ~(xy - 1);
  int x = 0, y = 0;
  for (int i = 0; i < n; i++) {
    // get all a[i]
    if (a[i] & pivot) {
      x ^= a[i];
    } else {
      y ^= a[i];
    }
    // separate all elements from 1 to n
    if ((i + 1) & pivot) {
      x ^= (i + 1);
    } else {
      y ^= (i + 1); 
    }
  }

  bool found = false;
  for (int i = 0; i < n; i++) {
    if (a[i] == x) {
      found = true;
    }
  }


  if (!found) {
    swap(x, y);
  }
  
  return vector <int>{x, y};
}   

int main() {
  
  return 0;
}