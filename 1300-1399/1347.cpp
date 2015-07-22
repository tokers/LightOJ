/*************************************************************************
    > File Name: LightOJ1347.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月22日 星期三 18时43分58秒
 ************************************************************************/
 
#include <iostream>
#include <fstream>
#include <cstring>
#include <climits>
#include <deque>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>
#include <string>
#include <vector>
#include <cstdio>
#include <bitset>
#include <functional>
#include <algorithm>
 
using namespace std;
 
const double pi = acos(-1.0);
const int inf = 0x3f3f3f3f;
const double eps = 1e-15;
typedef long long LL;
typedef unsigned long long ULL;
typedef pair <int, int> PLL;
const LL INF = (1LL << 60);
 
int belong[15010];
char str[5010];
 
class SuffixArray {
    public:
        static const int N = 15010;
        int init[N];
        int X[N];
        int Y[N];
        int Rank[N];
        int sa[N];
        int height[N];
        int buc[N];
        int size;
 
        void clear() {
            size = 0;
        }
 
        void insert(int n) {
            init[size++] = n;
        }
 
        bool cmp(int *r, int a, int b, int l) {
            return (r[a] == r[b] && r[a + l] == r[b + l]);
        }
 
        void getsa(int m = 256) {
            init[size] = 0;
            int l, p, *x = X, *y = Y, n = size + 1;
            for (int i = 0; i < m; ++i) {
                buc[i] = 0;
            }
            for (int i = 0; i < n; ++i) {
                ++buc[x[i] = init[i]];
            }
            for (int i = 1; i < m; ++i) {
                buc[i] += buc[i - 1];
            }
            for (int i = n - 1; i >= 0; --i) {
                sa[--buc[x[i]]] = i;
            }
            for (int l = 1, p = 1; l <= n && p < n; m = p, l *= 2) {
                p = 0;
                for (int i = n - l; i < n; ++i) {
                    y[p++] = i;
                }
                for (int i = 0; i < n; ++i) {
                    if (sa[i] >= l) {
                        y[p++] = sa[i] - l;
                    }
                }
                for (int i = 0; i < m; ++i) {
                     buc[i] = 0;
                }
                for (int i = 0; i < n; ++i) {
                    ++buc[x[y[i]]];
                }
                for (int i = 1; i < m; ++i) {
                    buc[i] += buc[i - 1];
                }
                for (int i = n - 1; i >= 0; --i) {
                    sa[--buc[x[y[i]]]] = y[i];
                }
                int i;
                for (swap(x, y), x[sa[0]] = 0, p = 1, i = 1; i < n; ++i) {
                    x[sa[i]] = cmp(y, sa[i - 1], sa[i], l) ? p - 1: p++;
                }
            }
        }
 
        void getheight() {
            int h = 0, n = size;
            for (int i = 0; i <= n; ++i) {
                Rank[sa[i]] = i;
            }
            height[0] = 0;
            for (int i = 0; i < n; ++i) {
                if (h > 0) {
                    --h;
                }
                int j = sa[Rank[i] - 1];
                for (; i + h < n && j + h < n && init[i + h] == init[j + h]; ++h);
                height[Rank[i] - 1] = h;
            }
        }
 
        bool judge(int len) {
            bool has[3];
            has[0] = has[1] = has[2] = 0;
            for (int i = 1; i <= size; ++i) {
                if (height[i - 1] >= len) {
                    if (belong[sa[i]] != -1) {
                        has[belong[sa[i]]] = 1;
                    }
                }
                else {
                    has[0] = has[1] = has[2] = 0;
                    if (belong[sa[i]] != -1) {
                        has[belong[sa[i]]] = 1;
                    }
                }
                if (has[0] + has[1] + has[2] == 3) {
                    return 1;
                }
            }
            return 0;
        }
 
        int solve() {
            int l = 0, r = size, mid;
            int ans = 0;
            while (l <= r) {
                mid = (l + r) >> 1;
                if (judge(mid)) {
                    ans = mid;
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            return ans;
        }
}SA;
 
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        SA.clear();
        int cnt = 0;
            for (int i = 0; i < 3; ++i) {
            scanf("%s", str);
            int len = strlen(str);
            if (i == 1) {
                SA.insert(40);
                belong[cnt++] = -1;
            }
            else if (i == 2) {
                SA.insert(48);
                belong[cnt++] = -1;
            }
            for (int j = 0; j < len; ++j) {
                SA.insert(str[j] - 'a' + 1);
                belong[cnt++] = i;
            }
        }
        SA.getsa(130);
        SA.getheight();
        printf("Case %d: %d\n", icase++, SA.solve());
    }
    return 0;
}
