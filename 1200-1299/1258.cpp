/*************************************************************************
    > File Name: LightOJ1258.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月22日 星期三 10时30分32秒
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
 
char str[2000100];
char S[1000100];
int p[2000100];
 
void manacher(int cnt) {
    memset(p, 0, sizeof(p));
    int MaxId = 0, id;
    for (int i = 1; i < cnt; ++i) {
        if (MaxId > i) {
            p[i] = min(MaxId - i, p[2 * id - i]);
        }
        else {
            p[i] = 1;
        }
        while (str[i + p[i]] == str[i - p[i]]) {
            ++p[i];
        }
        if (p[i] + i > MaxId) {
            MaxId = p[i] + i;
            id = i;
        }
    }
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%s", S);
        int len = strlen(S);
        int cnt = 0;
        str[cnt++] = '?';
        str[cnt++] = '#';
        for (int i = 0; i < len; ++i) {
            str[cnt++] = S[i];
            str[cnt++] = '#';
        }
        str[cnt] = 0;
        manacher(cnt);
        int x, pos;
        int ans = inf;
        for (int i = 2; i < cnt; ++i) {
            pos = i / 2 - 1;
            if (str[i] == '#') {
                x = (p[i] - 1) / 2;
                if (pos + x == len - 1) {
                    ans = min(ans, pos - x + 1);
                }
            }
            else {
                x = (p[i] - 1) / 2;
                if (pos + x == len - 1) {
                    ans = min(ans, pos - x);
                }
            }
        }
        printf("Case %d: %d\n", icase++, ans + len);
    }
    return 0;
}
