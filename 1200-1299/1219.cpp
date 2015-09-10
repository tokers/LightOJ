/*************************************************************************
    > File Name: LightOJ1219.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年09月10日 星期四 13时38分24秒
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
 
const int N = 10010;
vector <int> tree[N];
int Arr[N];
int in[N];
int ans;
 
void dfs(int u, int fa) {
    int size = tree[u].size();
    for (int i = 0; i < size; ++i) {
        int v = tree[u][i];
        dfs(v, u);
    }
    if (Arr[u] != 1) {
        ans += abs(Arr[u] - 1);
        Arr[fa] += (Arr[u] - 1);
    }
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, u, v, k;
        memset(in, 0, sizeof(in));
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            tree[i].clear();
        }
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &u);
            scanf("%d", &Arr[u]);
            scanf("%d", &k);
            while (k--) {
                scanf("%d", &v);
                ++in[v];
                tree[u].push_back(v);
            }
        }
        int root;
        for (int i = 1; i <= n; ++i) {
            if (in[i] == 0) {
                root = i;
                break;
            }
        }
        ans = 0;
        dfs(root, -1);
        printf("Case %d: %d\n", icase++, ans);
    }
    return 0;
}
