#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>
#include <iostream>
 
using namespace std;
 
const int N = 10010;
 
struct Node {
    int x, y;
 
    bool operator < (const Node& b) const {
        return (y < b.y);
    }
}Po[N], qujian[N];
 
int main() {
    int t, icase = 1, S, D, k, n;
    scanf("%d", &t);
    while (t--) {
        scanf("%d%d%d%d", &k, &n, &S, &D);
        for (int i = 0; i < n; ++i) {
            scanf("%d%d", &Po[i].x, &Po[i].y);
        }
        int l = 1, r = D, mid, ans = -1;
        while (l <= r) {
            mid = (l + r) >> 1;
            bool flag = 1;
            for (int i = 0; i < n; ++i) {
                int x = Po[i].x, y = Po[i].y;
                if (y - k + mid > D) {
                    flag = 0;
                    break;
                }
                double a = D + (y - k + mid), b = D - (y - k + mid);
                double x1 = x * 1.0 + sqrt(a * b);
                double x2 = x * 1.0 - sqrt(a * b);
                qujian[i].y = (int)floor(x1);
                qujian[i].x = (int)ceil(x2);
            }
            if (!flag) {
                r = mid - 1;
                continue;
            }
            sort(qujian, qujian + n);
            int i = 0;
            int cnt = 0;
            while (i < n) {
                int pos = qujian[i].y;
                ++cnt;
                while (i < n && pos <= qujian[i].y && pos >= qujian[i].x) {
                    ++i;
                }
            }
            if (cnt <= S) {
                ans = mid;
                l = mid + 1;
            }
            else {
                r = mid - 1;
            }
        }
        if (ans == -1) {
            printf("Case %d: impossible\n", icase++);
        }
        else {
            printf("Case %d: %d\n", icase++, ans);
        }
    }
    return 0;
}
