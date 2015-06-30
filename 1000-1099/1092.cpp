/*************************************************************************
    > File Name: LightOJ1092.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月30日 星期二 13时35分00秒
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
 
const int N = 70;
int a[N][N]; //增广矩阵
int x[N];
int free_num; //自由变元个数
int free_x[N]; //存放不确定变元
 
/**************************************************
 * Gauss-Jordan elimination
 * -2:浮点数解, 无整数解
 * -1表示无解
 * 0表示有唯一解
 * 大于0表示无穷多个解, 并且返回自由变元个数
 *************************************************/
 
int Gauss(int equ, int var) {
    int max_r; //当前列里, 绝对值最大的行编号
    int col;
    int free_num = 0;
 
    for (int i = 0; i <= var; ++i) {
        x[i] = 0;
    }
 
    col = 0;
    int k;
    //开始转换阶梯矩阵
    for (k = 0; k < equ && col < var; ++k, ++col) {
        max_r = k;
        for (int i = k + 1; i < equ; ++i) {
            if (abs(a[i][col]) > abs(a[max_r][col])) {
                max_r = i;
            }
        }
        if (a[max_r][col] == 0) {
            --k;
            free_x[free_num++] = col;
            continue;
        }
        if (max_r != k) {
            for (int j = col; j < var + 1; ++j) {
                swap(a[k][j], a[max_r][j]);
            }
        }
        for (int i = k + 1; i < equ; ++i) {
            if (a[i][col]) {
                for (int j = col; j < var + 1; ++j) {
                    a[i][j] ^= a[k][j];
                }
            }
        }
    }
    for (int i = k; i < equ; ++i) {
        if (a[i][col]) {
            return -1;
        }
    }
    if (k < var) {
        return var - k;
    }
    for (int i = var - 1; i >= 0; --i) {
        x[i] = a[i][var];
        for (int j = i + 1; j < var; ++j) {
            x[i] ^= (a[i][j] && x[j]);
        }
    }
    return 0;
}
 
char mat[10][10];
int Id[10][10];
 
int solve(int n, int m) {
    memset(a, 0, sizeof(a));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            a[Id[i][j]][Id[i][j]] = 1;
            if (i > 0) {
                a[Id[i][j]][Id[i - 1][j]] = 1;
                if (j > 0) {
                    a[Id[i][j]][Id[i - 1][j - 1]] = 1;
                }
                if (j + 1 < m) {
                    a[Id[i][j]][Id[i - 1][j + 1]] = 1;
                }
            }
            if (i + 1 < n) {
                a[Id[i][j]][Id[i + 1][j]] = 1;
                if (j > 0) {
                    a[Id[i][j]][Id[i + 1][j - 1]] = 1;
                }
                if (j + 1 < m) {
                    a[Id[i][j]][Id[i + 1][j + 1]] = 1;
                }
            }
            if (j > 0) {
                a[Id[i][j]][Id[i][j - 1]] = 1;
                if (i > 0) {
                    a[Id[i][j]][Id[i - 1][j - 1]] = 1;
                }
                if (i + 1 < n) {
                    a[Id[i][j]][Id[i + 1][j - 1]] = 1;
                }
            }
            if (j + 1 < m) {
                a[Id[i][j]][Id[i][j + 1]] = 1;
                if (i > 0) {
                    a[Id[i][j]][Id[i - 1][j + 1]] = 1;
                }
                if (i + 1 < n) {
                    a[Id[i][j]][Id[i + 1][j + 1]] = 1;
                }
            }
            if (mat[i][j] == '.') {
                a[Id[i][j]][n * m] = 1;
            }
            else {
                a[Id[i][j]][n * m] = 0;
            }
        }
    }
    int t = Gauss(n * m, n * m);
    if (t == -1) {
        return t;
    }
    if (t == 0) {
        int ans = 0;
        for (int i = 0; i < n * m; ++i) {
            ans += x[i];
        }
        return ans;
    }
    int tot = (1 << t); //t个自由变元, 2^t种情况
    int ans = inf;
    for (int i = 0; i < tot; ++i) {
        int cnt = 0;
        for (int j = 0; j < t; ++j) {
            if (i & (1 << j)) {
                x[free_x[j]] = 1;
                ++cnt;
            }
            else {
                x[free_x[j]] = 0;
            }
        }
        for (int j = n * m - t - 1; j >= 0; --j) {
            int idx;
            for (idx = j; idx < n * m; ++idx) {
                if (a[j][idx]) {
                    break;
                }
            }
            x[idx] = a[j][n * m];
            for (int l = idx + 1; l < n * m; ++l) {
                if (a[j][l]) {
                    x[idx] ^= x[l];
                }
            }
            cnt += x[idx];
        }
        ans = min(ans, cnt);
    }
    return ans;
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m, ret = 0;
        scanf("%d%d", &n, &m);
        for (int i = 0; i < n; ++i) {
            scanf("%s", mat[i]);
            for (int j = 0; j < m; ++j) {
                Id[i][j] = ret++;
            }
        }
        int ans = solve(n, m);
        if (ans == -1) {
            printf("Case %d: impossible\n", icase++);
            continue;
        }
        printf("Case %d: %d\n", icase++, ans);
    }
    return 0;
}
 
