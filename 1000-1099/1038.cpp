    /*************************************************************************
        > File Name: LightOJ1038.cpp
        > Author: ALex
        > Mail: zchao1995@gmail.com
        > Created Time: 2015年04月29日 星期三 19时40分52秒
     ************************************************************************/
     
    #include <functional>
    #include <algorithm>
    #include <iostream>
    #include <fstream>
    #include <cstring>
    #include <cstdio>
    #include <cmath>
    #include <cstdlib>
    #include <queue>
    #include <stack>
    #include <map>
    #include <bitset>
    #include <set>
    #include <vector>
     
    using namespace std;
     
    const double pi = acos(-1.0);
    const int inf = 0x3f3f3f3f;
    const double eps = 1e-15;
    typedef long long LL;
    typedef pair <int, int> PLL;
     
    double dp[100110];
     
    double dfs(int num) {
        if (dp[num] != -1) {
            return dp[num];
        }
        int cnt = 2;
        double ans = 0;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                ++cnt;
                ans += dfs(num / i);
                if (num / i != i) {
                    ans += dfs(i);
                    ++cnt;
                }
            }
        }
        ans += cnt;
        ans /= (cnt - 1);
        return dp[num] = ans;
    }
     
    int main() {
        int t;
        scanf("%d",&t);
        int icase = 1;
        while (t--) {
            int n;
            scanf("%d", &n);
            for (int i = 1; i <= n; ++i) {
                dp[i] = -1;
            }
            dp[1] = 0;
            printf("Case %d: %.12f\n", icase++, dfs(n));
        }
        return 0;
    }
