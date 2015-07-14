/*************************************************************************
    > File Name: LightOJ1236.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月12日 星期日 18时14分29秒
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
 
int prime[700000];
bool valid[10000100];
int tot;
 
void getPrime() {
    int n = 10000000;
    for (int i = 2; i <= n; ++i) {
        valid[i] = 1;
    }
    tot = 0;
    valid[1] = 0;
    for (int i = 2; i <= n; ++i) {
        if (valid[i]) {
            prime[++tot] = i;
        }
        for (int j = 1; ((j <= tot) && (i * prime[j] <= n)); ++j) {
            valid[i * prime[j]] = 0;
            if (i % prime[j] == 0) {
                break;
            }
        }
    }
}
 
vector < pair<LL, int> > primefac;
vector < pair<LL, int> > fac;
 
void dfs(int now, LL num, int sta) {
    if (now == (int)primefac.size()) {
        fac.push_back(make_pair(num, sta));
        return;
    }
    dfs(now + 1, num, sta);
    for (int i = 1; i <= primefac[now].second; ++i) {
        int newsta = sta;
        if (i == primefac[now].second) {
            newsta |= (1 << now);
        }
        num *= primefac[now].first;
        dfs(now + 1, num, newsta);
    }
}
 
int main() {
    int icase = 1, t;
    getPrime();
    scanf("%d", &t);
    while (t--) {
        LL n;
        scanf("%lld", &n);
        if (n == 1) {
            printf("Case %d: 1\n", icase++);
            continue;
        }
        primefac.clear();
        fac.clear();
        LL tmp = n;
        for (int i = 1; i <= tot && prime[i] <= tmp / prime[i]; ++i) {
            if (tmp % prime[i] == 0) {
                int cnt = 0;
                while (tmp % prime[i] == 0) {
                    tmp /= prime[i];
                    ++cnt;
                }
                primefac.push_back(make_pair(prime[i], cnt));
            }
        }
        if (tmp > 1) {
            primefac.push_back(make_pair(tmp, 1));
        }
        dfs(0, 1, 0);
        int ans = (int)fac.size();
        int size = ans;
        int m = primefac.size();
        sort(fac.begin(), fac.end());
        for (int i = size - 2; i >= 0; --i) {
            if (fac[i].first < n / fac[i].first) {
                break;
            }
            for (int j = 0; j < i; ++j) {
                if ((fac[j].second | fac[i].second) == (1 << m) - 1) {
                    ++ans;
                }
            }
        }
        printf("Case %d: %d\n", icase++, ans);
    }
    return 0;
}
