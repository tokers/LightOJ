/*************************************************************************
    > File Name: LightOJ1333.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年09月25日 星期五 19时25分35秒
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
 
const LL mod = 1000000000LL;
 
LL fastpow(LL a, LL b) {
    LL res = 1;
    while (b) {
        if (b & 1) {
            res = res * a % mod;
        }
        a = a * a % mod;
        b >>= 1;
    }
    return res;
}
 
struct Node {
    int x, y;
 
    bool operator < (const Node &b) const {
        if (y == b.y) {
            return x < b.x;
        }
        return y < b.y;
    }
}block[555];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m, k, b;
        scanf("%d%d%d%d", &n, &m, &k, &b);
        int x, y;
        for (int i = 1; i <= b; ++i) {
            scanf("%d%d", &block[i].x, &block[i].y);
        }
        sort(block + 1, block + b + 1);
        LL cur = 1, res = 1;
        int col = 0, row = 0, cnt = 0;
        for (int i = 1; i <= b; ++i) {
            if (block[i].y == col) {
                if (block[i].x - 1 - row >= 1) {
                    cur = cur * k % mod;
                    cur = cur * fastpow(k - 1, block[i].x - 1 - row - 1) % mod;
                }
                row = block[i].x;
            }
            else {
                if (col > 0) {
                    if (n - row >= 1) {
                        cur = cur * k % mod;
                        cur = cur * fastpow(k - 1, n - row - 1) % mod;
                    }
                    res = res * cur % mod;
                }
                ++cnt;
                col = block[i].y;
                if (block[i].x >= 2) {
                    cur = k * fastpow(k - 1, block[i].x - 2) % mod;
                }
                else {
                    cur = 1;
                }
                row = block[i].x;
            }
        }
        if (col > 0) {
            if (n - row >= 1) {
                cur = cur * k % mod;
                cur = cur * fastpow(k - 1, n - row - 1) % mod;
            }
        }
        res = res * cur % mod;
        cur = fastpow(k - 1, n - 1);
        cur = cur * k % mod;
        res = res * fastpow(cur, m - cnt) % mod;
        printf("Case %d: %lld\n", icase++, res);
    }
    return 0;
}
