/*************************************************************************
    > File Name: LightOJ1135.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月09日 星期日 16时58分17秒
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
    int mod[3];
    int add;
}tree[N << 2];
 
void pushup(int p) {
    for (int i = 0; i < 3; ++i) {
        tree[p].mod[i] = tree[p << 1].mod[i] + tree[p << 1 | 1].mod[i];
    }
}
 
void build(int p, int l, int r) {
    tree[p].l = l;
    tree[p].r = r;
    tree[p].add = 0;
    if (l == r) {
        for (int i = 0; i < 3; ++i) {
            tree[p].mod[i] = 0;
        }
        tree[p].mod[0] = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(p << 1, l, mid);
    build(p << 1 | 1, mid + 1, r);
    pushup(p);
}
 
void pushdown(int p) {
    if (tree[p].add) {
        tree[p << 1].add = (tree[p << 1].add + tree[p].add) % 3;
        tree[p << 1 | 1].add = (tree[p << 1 | 1].add + tree[p].add) % 3;
        int m0 = tree[p << 1].mod[0];
        int m1 = tree[p << 1].mod[1];
        int m2 = tree[p << 1].mod[2];
        tree[p << 1].mod[tree[p].add] = m0;
        tree[p << 1].mod[(tree[p].add + 1) % 3] = m1;
        tree[p << 1].mod[(tree[p].add + 2) % 3] = m2;
 
        m0 = tree[p << 1 | 1].mod[0];
        m1 = tree[p << 1 | 1].mod[1];
        m2 = tree[p << 1 | 1].mod[2];
        tree[p << 1 | 1].mod[tree[p].add] = m0;
        tree[p << 1 | 1].mod[(tree[p].add + 1) % 3] = m1;
        tree[p << 1 | 1].mod[(tree[p].add + 2) % 3] = m2;
 
        tree[p].add = 0;
    }
}
 
void update(int p, int l, int r) {
    if (l <= tree[p].l && tree[p].r <= r) {
        tree[p].add = (tree[p].add + 1) % 3;
        int m0 = tree[p].mod[0];
        int m1 = tree[p].mod[1];
        int m2 = tree[p].mod[2];
        tree[p].mod[0] = m2;
        tree[p].mod[1] = m0;
        tree[p].mod[2] = m1;
        return;
    }
    pushdown(p);
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (r <= mid) {
        update(p << 1, l, r);
    }
    else if (l > mid) {
        update(p << 1 | 1, l, r);
    }
    else {
        update(p << 1, l, mid);
        update(p << 1 | 1, mid + 1, r);
    }
    pushup(p);
}
 
int query(int p, int l, int r) {
    if (l <= tree[p].l && tree[p].r <= r) {
        return tree[p].mod[0];
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
        int n, q;
        scanf("%d%d", &n, &q);
        build(1, 1, n);
        int x, y, ty;
        printf("Case %d:\n", icase++);
        while (q--) {
            scanf("%d%d%d", &ty, &x, &y);
            ++x, ++y;
            if (ty == 0) {
                update(1, x, y);
            }
            else {
                printf("%d\n", query(1, x, y));
            }
        }
    }
    return 0;
}
