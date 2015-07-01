/*************************************************************************
    > File Name: LightOJ1083.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月1日 星期三 9时26分36秒
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
 
const int N = 30010;
pair <int, int> st[N];
int Arr[N];
int L[N];
int R[N];
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%d", &Arr[i]);
        }
        int Top = 0;
        for (int i = n; i >= 1; --i) {
            if (Top == 0) {
                st[++Top] = make_pair(Arr[i], i);
            }
            else {
                while (Top > 0) {
                    pair <int, int> u = st[Top];
                    if (u.first > Arr[i]) {
                        --Top;
                        L[u.second] = i + 1;
                    }
                    else {
                        break;
                    }
                }
                st[++Top] = make_pair(Arr[i], i);
            }
        }
        while (Top > 0) {
            pair <int, int> u = st[Top--];
            L[u.second] = 1;
        }
        for (int i = 1; i <= n; ++i) {
            if (Top == 0) {
                st[++Top] = make_pair(Arr[i], i);
            }
            else {
                while (Top > 0) {
                    pair <int, int> u = st[Top];
                    if (u.first > Arr[i]) {
                        --Top;
                        R[u.second] = i - 1;
                    }
                    else {
                        break;
                    }
                }
                st[++Top] = make_pair(Arr[i], i);
            }
        }
        while (Top > 0) {
            pair <int, int> u = st[Top--];
            R[u.second] = n;
        }
        int ans = 0;
        for (int i = 1; i <= n; ++i) {
            int l = L[i];
            int r = R[i];
            ans = max(ans, (r - l + 1) * Arr[i]);
        }
        printf("Case %d: %d\n", icase++, ans);
    }
    return 0;
}

