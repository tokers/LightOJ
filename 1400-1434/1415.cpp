/*************************************************************************
    > File Name: LightOJ1415.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月05日 星期三 14时52分47秒
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
 
const int N = 200100;
int ty[N];
int h[N];
int L[N];
int pos[N];
int last[N];
int l[N];
int mx[N];
 
stack < pair<LL, int> > st;
struct SegTree {
    int l, r;
    LL add;
    LL val;
    LL s1, s2;
}tree[N << 2];
 
void pushdown(int p) {
    if (tree[p].add) {
        tree[p << 1].add = tree[p << 1 | 1].add = tree[p].add;
        tree[p << 1].s2 = tree[p << 1 | 1].s2 = tree[p].add;
        tree[p].add = 0;
        tree[p << 1].val = tree[p << 1].s2 + tree[p << 1].s1;
        tree[p << 1 | 1].val = tree[p << 1 | 1].s2 + tree[p << 1 | 1].s1;
    }
}
 
void pushup(int p) {
    tree[p].val = min(tree[p << 1].val, tree[p << 1 | 1].val);
    tree[p].s1 = min(tree[p << 1].s1, tree[p << 1 | 1].s1);
}
 
void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].add = 0;
    tree[p].val = tree[p].s1 = tree[p].s2 = INF;
    if (l == r) {
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}
 
void update(int p, int l, int r, LL val, bool flag) {
    if (l <= tree[p].l && r >= tree[p].r) {
        if (flag) {
            tree[p].add = val;
            tree[p].s2 = val;
        }
        else {
            tree[p].s1 = val;
        }
        tree[p].val = tree[p].s1 + tree[p].s2;
        return;
    }
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (r <= mid) {
        update(p << 1, l, r, val, flag);
    }
    else if (l > mid) {
        update(p << 1 | 1, l, r, val, flag);
    }
    else {
        update(p << 1, l, mid, val, flag);
        update(p << 1 | 1, mid + 1, r, val, flag);
    }
    pushup(p);
}
 
LL query(int p, int l, int r) {
    if (l <= tree[p].l && tree[p].r <= r) {
        return tree[p].val;
    }
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (r <= mid) {
        return query(p << 1, l, r);
    }
    else if (l > mid) {
        return query(p << 1 | 1, l, r);
    }
    else {
        return min(query(p << 1, l, mid), query(p << 1 | 1, mid + 1, r));
    }
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        memset(last, -1, sizeof(last));
        memset(pos, -1, sizeof(pos));
        for (int i = 1; i <= n; ++i) {
            scanf("%d%d", &ty[i], &h[i]);
            if (i == 1) {
                mx[i] = h[i];
            }
            else {
                mx[i] = max(mx[i - 1], h[i]);
            }
            last[i] = pos[ty[i]];
            pos[ty[i]] = i;
        }
        for (int i = n; i >= 1; --i) {
            while (!st.empty()) {
                PLL now = st.top();
                if (now.second < h[i]) {
                    st.pop();
                    L[now.first] = i + 1;
                }
                else {
                    break;
                }
            }
            st.push(make_pair(i, h[i]));
        }
        while (!st.empty()) {
            PLL now = st.top();
            st.pop();
            L[now.first] = 1;
        }
        l[1] = 0;
        for (int i = 2; i <= n; ++i) {
            l[i] = max(l[i - 1], last[i]);
        }
        build(1, 1, n);
        LL ans;
        if (n == 1) {
            ans = h[1];
        }
        update(1, 2, 2, h[1], 0);
        for (int i = 2; i <= n; ++i) {
            update(1, L[i], i, h[i], 1);
            ans = query(1, l[i] + 1, i);
            if (l[i] == 0) {
                ans = min(ans, (LL)mx[i]);
            }
            if (i < n) {
                update(1, i + 1, i + 1, ans, 0);
            }
        }
        printf("Case %d: %lld\n", icase++, ans);
    }
    return 0;
}
