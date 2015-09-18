/*************************************************************************
    > File Name: LightOJ1325.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年09月18日 星期五 16时59分31秒
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

const int MOD = 99991; 
const int N = 100005; 
struct hs { 
	bool flag; 
	int id; 
	int val; 

	void clear() { 
		flag = 0; 
		id = -1; 
		val = -1; 
	} 
}hs[N]; 

void init() { 
	for (int i = 0; i < N; ++i) { 
		hs[i].clear(); 
	} 
} 

void insert(LL val, LL id) { 
	LL t = val % MOD; 
	while (hs[t].flag && hs[t].val != val) { 
		++t; 
		t %= MOD; 
	} 
	if(!hs[t].flag) { 
		hs[t].flag = 1; 
		hs[t].id = id; 
		hs[t].val = val; 
	} 
} 

LL Find(LL val) { 
	LL t = val % MOD; 
	while (hs[t].flag && hs[t].val != val) { 
		++t; 
		t %= MOD; 
	} 
	if (!hs[t].flag) { 
		return -1; 
	} 
	return hs[t].id; 
} 

void exgcd(LL a, LL b, LL &x, LL &y) { 
	if (b == 0) { 
		x = 1; 
		y = 0; 
		return; 
	} 
	exgcd(b, a % b, x, y); 
	LL t = x; 
	x = y; 
	y = t - (a / b) * x; 
} 

LL BSGS(LL A, LL B, LL C) { 
	init(); 
	A %= C; 
	B %= C; 
	LL ret = 1; 
	for (int i = 0; i <= 50; ++i) { 
		if (ret == B) { 
			return i; 
		} 
		ret = ret * A % C; 
	} 
	LL ans = 1; 
	LL tmp, cnt = 0; 
	while ((tmp = __gcd(A, C)) != 1) { 
		if (B % tmp) { 
			return -1; 
		} 
		B /= tmp; 
		C /= tmp; 
		ans = ans * (A / tmp) % C; 
		++cnt; 
	} 
	LL M = ceil(sqrt(1.0 * C)); 
	LL t = 1; 
	for (int i = 0; i < M; ++i) { 
		insert(t, i); 
		t = t * A % C; 
	} 
	for (int i = 0; i < M; ++i) { 
		LL x, y; 
		exgcd(ans, C, x, y); 
		LL val = x * B % C; 
		val = (val % C + C) % C; 
		LL j = Find(val); 
		if (j != -1) { 
			return M * i + j + cnt; 
		} 
		ans = ans * t % C; 
	} 
	return -1; 
} 

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int a, b;
		scanf("%d%d", &a, &b);
		printf("Case %d: %lld\n", icase++, BSGS(a, b, 100000007));
	}
	return 0;
}
