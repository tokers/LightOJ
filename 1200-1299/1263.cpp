#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

const int N = 1010;
int Num[N], fa[N], val[N];

int Find(int x) {
	if (fa[x] == -1) {
		return x;
	}
	return fa[x] = Find(fa[x]);
}

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, m;
		scanf("%d%d", &n, &m);
		memset(fa, -1, sizeof(fa));
		int u, v;
		int sum = 0, Arr;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Arr);
			sum += Arr;
			Num[i] = 1;
			val[i] = Arr;
		}
		for (int i = 1; i <= m; ++i) {
			scanf("%d%d", &u, &v);
			int uu = Find(u), vv = Find(v);
			if (uu != vv) {
				fa[uu] = vv;
				Num[vv] += Num[uu];
				val[vv] += val[uu];
			}
		}
		printf("Case %d: ", icase++);
		if (sum % n) {
			printf("No\n");
			continue;
		}
		sum /= n;
		bool flag = 1;
		for (int i = 1; i <= n; ++i) {
			if (fa[i] == -1) {
				if (val[i] % Num[i] || val[i] / Num[i] != sum) {
					flag = 0;
					break;
				}
			}
		}
		printf("%s\n", flag ? "Yes" : "No");
	}
	return 0;
}
