/*************************************************************************
    > File Name: LightOJ1269.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年10月09日 星期五 18时51分22秒
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
 
struct Trie {
    int next[1700000][2];
    int end[1700000];
    int root, L;
 
    int newnode() {
        next[L][0] = next[L][1] = -1;
        end[L++] = 0;
        return L - 1;
    }
   
    void init() {
        L = 0;
        root = newnode();
    }
   
    void insert(int buf[]) {
        int now = root;
        for (int i = 32; i >= 0; --i) {
            if (next[now][buf[i]] == -1) {
                next[now][buf[i]] = newnode();
            }
            now = next[now][buf[i]];
        }
        ++end[now];
    }
 
    LL solve(int buf[]) {
        int now = root;
        LL ans = 0;
        for (int i = 32; i >= 0; --i) {
            if (buf[i]) {
                if (next[now][0] != -1) {
                    ans <<= 1;
                    ans |= 1;
                    now = next[now][0];
                }
                else {
                    ans <<= 1;
                    now = next[now][1];
                }
            }
            else {
                if (next[now][1] != -1) {
                    ans <<= 1;
                    ans |= 1;
                    now = next[now][1];
                }
                else {
                    ans <<= 1;
                    now = next[now][0];
                }
            }
        }
        return ans;
    }
 
    LL solve2(int buf[]) {
        LL ans = 0;
        int now = root;
        for (int i = 32; i >= 0; --i) {
            if (buf[i]) {
                if (next[now][1] != -1) {
                    ans <<= 1;
                    now = next[now][1];
                }
                else {
                    ans <<= 1;
                    ans |= 1;
                    now = next[now][0];
                }
            }
            else {
                if (next[now][0] != -1) {
                    ans <<= 1;
                    now = next[now][0];
                }
                else {
                    ans <<= 1;
                    ans |= 1;
                    now = next[now][1];
                }
            }
        }
        return ans;
    }
}T;
 
int buf[50010][40];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n, m;
        scanf("%d", &n);
        T.init();
        int val = 0;
        memset(buf[0], 0, sizeof(buf[0]));
        T.insert(buf[0]);
        LL ans = 0;
        LL ans2 = INF;
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &m);
            int cnt = 0;
            val ^= m;
            int tmp = val;
            memset(buf[i], 0, sizeof(buf[i]));
            while (tmp) {
                buf[i][cnt++] = tmp % 2;
                tmp >>= 1;
            }
            ans = max(ans, T.solve(buf[i]));
            ans2 = min(ans2, T.solve2(buf[i]));
            T.insert(buf[i]);
        }
        ans = max(ans, (LL)val);
        ans2 = min(ans2, (LL)val);
        printf("Case %d: %lld %lld\n", icase++, ans, ans2);
    }
    return 0;
}
