/*************************************************************************
    > File Name: LightOJ1255.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年07月22日 星期三 10时21分53秒
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
 
char A[1000100];
char B[1000100];
int nxt[1000100];
 
void getnxt() {
    int len = strlen(B);
    int j = 0, k = -1;
    nxt[0] = -1;
    while (j < len) {
        if (k == -1 || B[j] == B[k]) {
            nxt[++j] = ++k;
        }
        else {
            k = nxt[k];
        }
    }
}
 
int kmp() {
    int lena = strlen(A);
    int lenb = strlen(B);
    int ans = 0, i = 0, j = 0;
    while (i < lena && j < lenb) {
        if (j == -1 || A[i] == B[j]) {
            ++i;
            ++j;
            if (j == lenb) {
                ++ans;
                j = nxt[j];
            }
        }
        else {
            j = nxt[j];
        }
    }
    return ans;
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        scanf("%s%s", A, B);
        getnxt();
        printf("Case %d: %d\n", icase++, kmp());
    }
    return 0;
}
