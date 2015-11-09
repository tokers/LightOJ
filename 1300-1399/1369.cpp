#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>

using namespace std;

const int N = 100010;
int Arr[N];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		int n, q;
		scanf("%d%d", &n, &q);
		long long sum = 0;
		int xi = n - 1;
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &Arr[i]);
			sum += (long long)Arr[i] * xi;
			xi -= 2;
		}
		int ty, x, v;
		printf("Case %d:\n", icase++);
		while (q--) {
			scanf("%d", &ty);
			if (ty) {
				printf("%lld\n", sum);
			}
			else {
				scanf("%d%d", &x, &v);
				sum += (long long)(v - Arr[x + 1]) * (n - 1 - x * 2);
				Arr[x + 1] = v;
			}
		}
	}
	return 0;
}
