/*************************************************************************
    > File Name: LightOJ1100.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015/10/23 11:20:14
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

struct Query {
    int id, l, r, bid;

    bool operator < (const Query &ano) const {
        if (bid == ano.bid) {
            return r < ano.r;
        }
        return bid < ano.bid;
    }
}que[10010];

int Arr[100010];
set <int> st;
set <int> :: iterator it, it2;
int ans[10010];
int lastl, lastr;
int cnt[1010];

void query(int l, int r, int id) {
    if (id == 1) {
        lastl = l;
        lastr = r;
        for (int i = l; i <= r; ++i) {
            st.insert(Arr[i]);
            ++cnt[Arr[i]];
        }
    }
    else {
        for (int i = lastl; i < l; ++i) {
            --cnt[Arr[i]];
            if (cnt[Arr[i]] == 0) {
                st.erase(Arr[i]);
            }
        }
        for (int i = r + 1; i <= lastr; ++i) {
            --cnt[Arr[i]];
            if (cnt[Arr[i]] == 0) {
                st.erase(Arr[i]);
            }
        }
        for (int i = l; i < lastl; ++i) {
            if (cnt[Arr[i]] == 0) {
                st.insert(Arr[i]);
            }
            ++cnt[Arr[i]];
        }
        for (int i = lastr + 1; i <= r; ++i) {
            if (cnt[Arr[i]] == 0) {
                st.insert(Arr[i]);
            }
            ++cnt[Arr[i]];
        }
        lastl = l;
        lastr = r;
    }
}

int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, q;
        scanf("%d%d", &n, &q);
        int bsize = (int)sqrt(n + 0.0);
        st.clear();
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &Arr[i]);
        }
        for (int i = 1; i <= q; ++i) {
            scanf("%d%d", &que[i].l, &que[i].r);
            ++que[i].l, ++que[i].r;
            que[i].bid = que[i].l / bsize;
            que[i].id = i;
        }
        memset(cnt, 0, sizeof(cnt));
        sort(que + 1, que + q + 1);
        for (int i = 1; i <= q; ++i) {
            query(que[i].l, que[i].r, i);
            int mins = inf;
            for (it = st.begin(); it != st.end(); ++it) {
                int val = *it;
                if (cnt[val] >= 2) {
                    mins = 0;
                    break;
                }
                if (it != st.begin()) {
                    it2 = it;
                    --it2;
                    mins = min(mins, *it - *it2);
                }
                it2 = it;
                ++it2;
                if (it2 != st.end()) {
                    mins = min(mins, *it2 - *it);
                }
            }
            ans[que[i].id] = mins;
        }
        printf("Case %d:\n", icase++);
        for (int i = 1; i <= q; ++i) {
            printf("%d\n", ans[i]);
        }
    }
    return 0;
}
