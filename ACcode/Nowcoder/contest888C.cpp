#include <bits/stdc++.h>
using namespace std;
 
int a[1035][1035];
 
int main() {
  a[1][1] = 0;
  a[1][2] = 0;
  a[2][1] = 0;
  a[2][2] = 1;
  int n;
  cin >> n;
  int t = 2;
  while (t < n) {
    // you
    t <<= 1;
    for (int i = 1; i <= t/2; ++i) {
      for (int j = t/2+1; j <= t; ++j) {
        a[i][j] = a[i][j-t/2];
      }
    }
    // xia zuo
    for (int i = t/2+1; i <= t; ++i) {
      for (int j = 1; j <= t/2; ++j) {
        a[i][j] = a[i-t/2][j];
      }
    }
 
    // xia you
    for (int i = t/2+1; i <= t; ++i) {
      for (int j = t/2+1; j <= t; ++j) {
        a[i][j] = a[i][j-t/2] ^ 1;
      }
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      if (j > 1) cout << " ";
      cout << (a[i][j] == 0 ? 1 : -1);
    }
    cout << endl;
  }
  return 0;
}