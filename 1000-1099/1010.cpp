/*************************************************************************
  > File Name: LightOJ1010.cpp
  > Author: ALex
  > Mail: zchao1995@gmail.com
  > Created Time: 2015年06月08日 星期一 14时24分24秒
************************************************************************/

#include <functional>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <queue>
#include <stack>
#include <map>
#include <bitset>
#include <set>
#include <vector>

using namespace std;

const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef pair <int, int> PLL;

int main() {
  int t, icase = 1;
  scanf("%d", &t);
  while (t--) {
      int n, m;
      scanf("%d%d", &n, &m);
      int ans = 0;
      if (n >= 3 && m >= 3) {
          if (n * m % 2 == 0) {
              ans = n * m / 2;
          }
          else {
              int s = m / 2 + 1;
              ans += (n / 2 + 1) * s;
              ans += (n / 2) * (s - 1);
          }
      }
      else {
          if (n == 1) {
              ans = m;
          }
          else if (m == 1) {
              ans = n;
          }
          else {
              if (m == 2) {
                  swap(n, m);
              }
              if (m <= 3) {
                  ans = 4;
              }
              else {
                  int cnt = m / 2;
                  ans = (cnt / 2 + cnt % 2) * 4;
                  if (m % 2 && cnt % 2 == 0) {
                      ans += 2;
                  }
              }
          }
      }
      printf("Case %d: %d\n", icase++, ans);
  }
  return 0;
}
