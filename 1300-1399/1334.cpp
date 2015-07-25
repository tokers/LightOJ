/*************************************************************************
    > File Name: LightOJ1334.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月22日 星期三 21时05分15秒
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

const int N = 50010;
int R[N];
int L[N];
int nxt[N];
int dp[N];
int extend[N];
char D[N], G[N];

void getnxt(char str[]) {
	memset(dp, 0, sizeof(dp));
	int len = strlen(str);
	nxt[0] = -1;
	int j = 0, k = -1;
	while (j < len) {
		if (k == -1 || str[j] == str[k]) {
			nxt[++j] = ++k;
		}
		else {
			k = nxt[k];
		}
	}
	dp[0] = 1;
	for (int i = 1; i < len; ++i) {
		if (nxt[i + 1] >= 1) {
			dp[i] = dp[nxt[i + 1] - 1] + 1;
		}
		else {
			dp[i] = 1;
		}
		if (i == len - 1) {
			--dp[i];
		}
	}
}

void kmp(char A[], char B[], int pos[], bool flag) {
	int lenA = strlen(A);
	int lenB = strlen(B);
	int i = 0, j = 0;
	while (i < lenA && j < lenB) {
		if (j == -1 || A[i] == B[j]) {
			if (j != -1) {
				if (flag) {
					pos[i] = dp[j];
				}
				else {
					pos[lenA - i - 1] = dp[j];
				}
			}
			++i;
			++j;
			if (j == lenB) {
				j = nxt[j];
			}
		}
		else {
			j = nxt[j];
		}
	}
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		memset(L, 0, sizeof(L));
		memset(R, 0, sizeof(R));
		scanf("%s%s", D, G);
		int lenD = strlen(D);
		int lenG = strlen(G);
		getnxt(G);
		kmp(D, G, L, 1);
		reverse(D, D + lenD);
		reverse(G, G + lenG);
		getnxt(G);
		kmp(D, G, R, 0);
		LL ans = 0;
		for (int i = 0; i < lenD - 1; ++i) {
			ans += (LL)L[i] * R[i + 1];
		}
		printf("Case %d: %lld\n", icase++, ans);
	}
	return 0;
}
