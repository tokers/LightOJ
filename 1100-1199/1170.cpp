/*************************************************************************
    > File Name: LightOJ1170.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年08月19日 星期三 10时41分31秒
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
 
int H[1000100];
const int mod = 100000007;
int e[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
 
int mod_pow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) {
            res = (LL)res * a % mod;
        }
        b >>= 1;
        a = (LL)a * a % mod;
    }
    return res;
}
 
vector <PLL> pows;
 
int main() {
    H[0] = 0;
    H[1] = 1;
    H[2] = 2;
    for (int i = 3; i <= 1000000; ++i) {
        H[i] = (LL)H[i - 1] * (4 * i - 2) % mod * mod_pow(i + 1, mod - 2) % mod;
    }
    pows.clear();
    for (int i = 1; i < 2048; ++i) {
        int bit = 0;
        LL x = 1;
        for (int j = 0; j < 11; ++j) {
            if (i & (1 << j)) {
                x *= e[j];
                ++bit;
            }
        }
        if (x < 32) {
            pows.push_back(make_pair(x, bit));
        }
    }
    LL a, b;
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%lld%lld", &a, &b);
        int ans = 0;
        int size = pows.size();
        for (int i = 0; i < size; ++i) {
            int bit = pows[i].second;
            int sta = pows[i].first;
            int cnt = (int)pow(b, 1.0 / sta) - 1;
            int cnt2 = (int)pow(a - 1, 1.0 / sta) - 1;
            if (cnt2 > 0) {
                cnt -= cnt2;
            }
            if (bit & 1) {
                ans += cnt;
            }
            else {
                ans -= cnt;
            }
        }
        printf("Case %d: %d\n", icase++, H[ans]);
    }
    return 0;
}
