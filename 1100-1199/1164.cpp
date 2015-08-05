/*************************************************************************
    > File Name: LightOJ1164.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月05日 星期三 19时29分37秒
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
 
const int N = 100010;
struct SegTree {
    int l, r;
    LL sum;
    LL add;
}tree[N << 2];
 
void pushup(int p) {
    tree[p].sum = tree[p << 1].sum + tree[p << 1 | 1].sum;
}
 
void pushdown(int p) {
    if (tree[p].add) {
        tree[p << 1].sum += tree[p].add * (tree[p << 1].r - tree[p << 1].l + 1);
        tree[p << 1 | 1].sum += tree[p].add * (tree[p << 1 | 1].r - tree[p << 1 | 1].l + 1);
        tree[p << 1].add += tree[p].add;
        tree[p << 1 | 1].add += tree[p].add;
        tree[p].add = 0;
    }
}
 
void build(int p, int l, int r) {
    tree[p].add = 0;
    tree[p].l = l;
    tree[p].r = r;
    tree[p].sum = 0;
    if (l == r) {
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
}
 
void update(int p, int l, int r, int val) {
    if (l <= tree[p].l && tree[p].r <= r) {
        tree[p].add += val;
        tree[p].sum += (r - l + 1) * val;
        return;
    }
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (r <= mid) {
        update(p << 1, l, r, val);
    }
    else if (l > mid) {
        update(p << 1 | 1, l, r, val);
    }
    else {
        update(p << 1, l, mid, val);
        update(p << 1 | 1, mid + 1, r, val);
    }
    pushup(p);
}
 
LL query(int p, int l, int r) {
    if (l <= tree[p].l && tree[p].r <= r) {
        return tree[p].sum;
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
        return query(p << 1, l, mid) + query(p << 1 | 1, mid + 1, r);
    }
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d%d", &n, &m);
        build(1, 1, n);
        int x, y, v;
        int ty;
        printf("Case %d:\n", icase++);
        while (m--) {
            scanf("%d", &ty);
            if (ty == 0) {
                scanf("%d%d%d", &x, &y, &v);
                ++x, ++y;
                update(1, x, y, v);
            }
            else {
                scanf("%d%d", &x, &y);
                ++x;
                ++y;
                printf("%lld\n", query(1, x, y));
            }
        }
    }
    return 0;
}
