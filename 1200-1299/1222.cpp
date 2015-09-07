/*************************************************************************
    > File Name: LightOJ1222.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年09月07日 星期一 16时00分49秒
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
 
const int N = 55;
int un, vn;
int G[N][N];
int linker[N], lx[N], ly[N]; //匹配状态, x y点顶标
int slack[N];
bool visx[N], visy[N];
 
bool dfs(int x) {
    visx[x] = 1;
    for (int y = 0; y < vn; ++y) {
        if (visy[y]) {
            continue;
        }
        int tmp = lx[x] + ly[y] - G[x][y];
        if (tmp == 0) {
            visy[y] = 1;
            if (linker[y] == -1 || dfs(linker[y])) {
                linker[y] = x;
                return 1;
            }
        }
        else if (slack[y] > tmp) {
            slack[y] = tmp;
        }
    }
    return 0;
}
 
int KM() {
    memset(linker, -1, sizeof(linker));
    memset(ly, 0, sizeof(ly));
    for (int i = 0; i < un; ++i) {
        lx[i] = -inf;
        for (int j = 0; j < vn; ++j) {
            if (G[i][j] > lx[i]) {
                lx[i] = G[i][j];
            }
        }
    }
    for (int x = 0; x < un; ++x) {
        for (int i = 0; i < vn; ++i) {
            slack[i] = inf;
        }
        while (1) {
            memset(visx, 0, sizeof(visx));
            memset(visy, 0, sizeof(visy));
            if (dfs(x)) {
                break;
            }
            int d = inf;
            for (int i = 0; i < vn; ++i) {
                if (!visy[i] && d > slack[i]) {
                    d = slack[i];
                }
            }
            for (int i = 0; i < un; ++i) {
                if (visx[i]) {
                    lx[i] -= d;
                }
            }
            for (int i = 0; i < vn; ++i) {
                if (visy[i]) {
                    ly[i] += d;
                }
                else {
                    slack[i] -= d;
                }
            }
        }
    }
    int res = 0;
    for (int i = 0; i < vn; ++i) {
        if (linker[i] != -1) {
            res += G[linker[i]][i];
        }
    }
    return res;
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &un);
        vn = un;
        for (int i = 0; i < un; ++i) {
            for (int j = 0; j < vn; ++j) {
                scanf("%d", &G[i][j]);
            }
        }
        printf("Case %d: %d\n", icase++, KM());
    }
    return 0;
}
 
