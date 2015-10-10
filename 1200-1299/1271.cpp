/*************************************************************************
    > File Name: LightOJ1271.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年10月10日 星期六 15时33分58秒
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
 
const int N = 50010;
vector <int> edge[N];
bool vis[N];
int path[N];
int Arr[N];
vector <int> ans;
 
void bfs(int s, int t) {
    queue <int> qu;
    qu.push(s);
    vis[s] = 1;
    while (!qu.empty()) {
        int u = qu.front();
        qu.pop();
        if (u == t) {
            break;
        }
        int size = edge[u].size();
        for (int i = 0; i < size; ++i) {
            int v = edge[u][i];
            if (vis[v]) {
                continue;
            }
            vis[v] = 1;
            path[v] = u;
            qu.push(v);
        }
    }
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        int mx = 1;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &Arr[i]);
            mx = max(mx, Arr[i]);
        }
        for (int i = 1; i <= mx; ++i) {
            edge[i].clear();
            path[i] = -1;
            vis[i] = 0;
        }
        for (int i = 2; i <= n; ++i) {
            edge[Arr[i - 1]].push_back(Arr[i]);
            edge[Arr[i]].push_back(Arr[i - 1]);
        }
        for (int i = 1; i <= mx; ++i) {
            sort(edge[i].begin(), edge[i].end());
        }
        bfs(Arr[1], Arr[n]);
        ans.clear();
        int u = Arr[n];
        ans.push_back(u);
        while (path[u] != -1) {
            u = path[u];
            ans.push_back(u);
        }
        int size = ans.size();
        printf("Case %d:\n", icase++);
        for (int i = size - 1; i >= 0; --i) {
            printf("%d", ans[i]);
            if (i) {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
