/*************************************************************************
    > File Name: LightOJ1209.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年09月07日 星期一 13时24分26秒
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
 
const int N = 510;
struct Edge {
    int to;
    int nxt;
}edge[N * N];
int head[N], tot;
 
void addedge(int from, int to) {
    edge[tot].to = to;
    edge[tot].nxt = head[from];
    head[from] = tot++;
}
 
int match[N];
bool vis[N];
 
bool dfs(int u) {
    for (int i = head[u]; ~i; i = edge[i].nxt) {
        int v = edge[i].to;
        if (!vis[v]) {
            vis[v] = 1;
            if (match[v] == -1 || dfs(match[v])) {
                match[v] = u;
                return 1;
            }
        }
    }
    return 0;
}
 
int hungry(int n) {
    memset(match, -1, sizeof(match));
    int ans = 0;
    for (int i = 1; i <= n; ++i) {
        memset(vis, 0, sizeof(vis));
        if (dfs(i)) {
            ++ans;
        }
    }
    return ans / 2;
}
 
struct node {
    bool flag1, flag2;
    int love, hate;
}que[N];
 
char str[10];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int m, f, n;
        memset(head, -1, sizeof(head));
        tot = 0;
        scanf("%d%d%d", &m, &f, &n);
        for (int i = 1; i <= n; ++i) {
            for (int k = 0; k < 2; ++k) {
                scanf("%s", str);
                int u = 0;
                int len = strlen(str);
                for (int j = 1; j < len; ++j) {
                    u = u * 10 + str[j] - '0';
                }
                if (k == 0) {
                    que[i].love = u;
                    if (str[0] == 'M') {
                        que[i].flag1 = 0;
                    }
                    else {
                        que[i].flag1 = 1;
                    }
                }
                else {
                    que[i].hate = u;
                    if (str[0] == 'M') {
                        que[i].flag2 = 0;
                    }
                    else {
                        que[i].flag2 = 1;
                    }
                }
            }
        }
        for (int i = 1; i <= n; ++i) {
            for (int j = i + 1; j <= n; ++j) {
                if (que[i].flag2 == que[j].flag1 && que[i].hate == que[j].love) {
                    addedge(i, j);
                    addedge(j, i);
                }
                else if (que[i].flag1 == que[j].flag2 && que[i].love == que[j].hate) {
                    addedge(i, j);
                    addedge(j, i);
                }
            }
        }
        printf("Case %d: %d\n", icase++, n - hungry(n));
    }
    return 0;
}
