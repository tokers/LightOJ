/*************************************************************************
    > File Name: LightOJ1428.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年07月22日 星期三 14时54分15秒
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
char A[N], B[N];
int nxt[N];
vector <int> go;
vector <int> go2;

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

void kmp() {
	int lena = strlen(A);
	int lenb = strlen(B);
	int i = 0, j = 0;
	go.clear();
	go2.clear();
	while (i < lena && j < lenb) {
		if (j == -1 || A[i] == B[j]) {
			++i;
			++j;
			if (j == lenb) {
				go.push_back(i - lenb);
				go2.push_back(i - 1);
				j = nxt[j];
			}
		}
		else {
			j = nxt[j];
		}
	}
}

class SuffixArray {
	public:
		static const int N = 50010;
		int init[N];
		int X[N];
		int Y[N];
		int Rank[N];
		int sa[N];
		int height[N];
		int buc[N];
		int size;

		void clear() {
			size = 0;
		}

		void insert(int n) {
			init[size++] = n;
		}

		bool cmp(int *r, int a, int b, int l) {
			return (r[a] == r[b] && r[a + l] == r[b + l]);
		}

		void getsa(int m = 256) {
			init[size] = 0;
			int l, p, *x = X, *y = Y, n = size + 1;
			for (int i = 0; i < m; ++i) {
				buc[i] = 0;
			}
			for (int i = 0; i < n; ++i) {
				++buc[x[i] = init[i]];
			}
			for (int i = 1; i < m; ++i) {
				buc[i] += buc[i - 1];
			}
			for (int i = n - 1; i >= 0; --i) {
				sa[--buc[x[i]]] = i;
			}
			for (l = 1, p = 1; l <= n && p < n; m = p, l *= 2) {
				p = 0;
				for (int i = n - l; i < n; ++i) {
					y[p++] = i;
				}
				for (int i = 0; i < n; ++i) {
					if (sa[i] >= l) {
						y[p++] = sa[i] - l;
					}
				}
				for (int i = 0; i < m; ++i) {
					buc[i] = 0;
				}
				for (int i = 0; i < n; ++i) {
					++buc[x[y[i]]];
				}
				for (int i = 1; i < m; ++i) {
					buc[i] += buc[i - 1];
				}
				for (int i = n - 1; i >= 0; --i) {
					sa[--buc[x[y[i]]]] = y[i];
				}
				int i;
				for (swap(x, y), x[sa[0]] = 0, p = 1, i = 1; i < n; ++i) {
					x[sa[i]] = cmp(y, sa[i - 1], sa[i], l) ? p - 1: p++;
				}
			}
		}

		void getheight() {
			int h = 0, n = size;
			for (int i = 0; i <= n; ++i) {
				Rank[sa[i]] = i;
			}
			height[0] = 0;
			for (int i = 0; i < n; ++i) {
				if (h > 0) {
					--h;
				}
				int j = sa[Rank[i] - 1];
				for (; i + h < n && j + h < n && init[i + h] == init[j + h]; ++h);
				height[Rank[i] - 1] = h;
			}
		}

		LL solve(int len) {
			int v = strlen(A);
			LL ans = 0;
			for (int i = 1; i <= size; ++i) {
				int s = sa[i] + height[i - 1]; // 此后缀的有效前缀
				int num = go.size();
				if (!num) {
					ans += size - s;
				}
				else {
					int en;
					if (go[0] >= sa[i]) {
						en = go[0] + len - 1;
						if (en >= s) {
							ans += en - s;
						}
						continue;
					}
					int id = lower_bound(go.begin(), go.end(), sa[i]) - go.begin();
					if (id == num) {
						ans += size - s;
					}
					else {
						if (go[id] + len - 1 <= s) {
							continue;
						}
						if (go[num - 1] + len - 1 <= s) {
							continue;
						}
						int id2 = lower_bound(go2.begin() + id, go2.end(), s) - go2.begin();
						int pos = go2[id2];
						ans += pos - s;
					}
				}
			}
			return ans;
		}
}SA;

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		scanf("%s%s", A, B);
		getnxt();
		kmp();
		int len = strlen(A);
		SA.clear();
		for (int i = 0; i < len; ++i) {
			SA.insert(A[i] - 'a' + 1);
		}
		SA.getsa(30);
		SA.getheight();
		int lenb = strlen(B);
		printf("Case %d: %lld\n", icase++, SA.solve(lenb));
	}
	return 0;
}
