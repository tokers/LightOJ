#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <cstdio>
 
using namespace std;
 
int dp[(1 << 15) + 10][16];
int nxt[110];
bool vis[20];
int extend[110];
int same[20][20];
string old[20], str[20];
const int inf = 0x3f3f3f3f;
string Myans;
int m;
 
void extend_kmp(string S, string T) {
    int lens = S.length();
    int lent = T.length();
    nxt[0] = lent;
    int i, j, p, L;
    j = 0;
    while (j + 1 < lent && T[j] == T[j + 1]) {
        ++j;
    }
    nxt[1] = j;
    int a = 1;
    for (i = 2; i < lent; ++i) {
        p = nxt[a] + a - 1;
        L = nxt[i - a];
        if (i + L < p + 1) {
            nxt[i] = L;
        }
        else {
            j = max(0, p - i + 1);
            while (i + j < lent && T[i + j] == T[j]) {
                ++j;
            }
            nxt[i] = j;
            a = i;
        }
    }
    j = 0;
    while (j < lens && S[j] == T[j]) {
        ++j;
    }
    extend[0] = j;
    a = 0;
    for (i = 1; i < lens; ++i) {
        p = extend[a] + a - 1;
        L = nxt[i - a];
        if (L + i < p + 1) {
            extend[i] = L;
        }
        else {
            j = max(0, p - i + 1);
            while (i + j < lens && j < lent && S[i + j] == T[j]) {
                ++j;
            }
            extend[i] = j;
            a = i;
        }
    }
}
 
void dfs(int mask, int last, string tmp) {
    int l = tmp.length();
    if (Myans != "" && Myans.substr(0, l) < tmp) {
        return;
    }
    if (!mask) {
        if (Myans == "") {
            Myans = tmp;
            return;
        }
        Myans = min(Myans, tmp);
        return;
    }
    for (int i = 0; i < m; ++i) {
        if (!(mask & (1 << i))) {
            continue;
        }
        int len = str[i].length();
        if (dp[mask | (1 << last)][last] == dp[mask][i] + (int)str[last].length() - same[last][i]) {
            string news = tmp;
            for (int j = same[last][i]; j < len; ++j) {
                news += str[i][j];
            }
            dfs(mask ^ (1 << i), i, news);
        }  
    }
}
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; ++i) {
            cin >> old[i];
        }
        memset(dp, inf, sizeof(dp));
        memset(vis, 0, sizeof(vis));
        m = 0;
        for (int i = 0; i < n; ++i) {
            if (vis[i]) {
                continue;
            }
            for (int j = 0; j < n; ++j) {
                if (vis[j]) {
                    continue;
                }
                if (i != j && old[i].find(old[j]) != -1) {
                    vis[j] = 1;
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                str[m++] = old[i];
            }
        }
        memset(same, 0, sizeof(same));
        sort(str, str + m);
        for (int i = 0; i < m; ++i) {
            dp[1 << i][i] = (int)str[i].length();
            for (int j = 0; j < m; ++j) {
                if (i == j) {
                    continue;
                }
                extend_kmp(str[i], str[j]);
                int l = str[i].length();
                for (int k = 0; k < l; ++k) {
                    if (k + extend[k] - 1 == l - 1) {
                        same[i][j] = extend[k];
                        break;
                    }
                }
            }
        }
        for (int i = 1; i < (1 << m); ++i) {
            for (int j = 0; j < m; ++j) {
                if (dp[i][j] == inf) {
                    continue;
                }
                for (int k = 0; k < m; ++k) {
                    if (i & (1 << k)) {
                        continue;
                    }
                    dp[i | (1 << k)][k] = min(dp[i | (1 << k)][k], dp[i][j] + (int)str[k].length() - same[k][j]);
                }
            }
        }
        int ans = inf;
        for (int i = 0; i < m; ++i) {
            ans = min(ans, dp[(1 << m) - 1][i]);
        }
        int mask = (1 << m) - 1;
        Myans = "";
        string tmp = "";
        int u;
        for (int i = 0; i < m; ++i) {
            if (dp[(1 << m) - 1][i] == ans) {
                tmp = str[i];
                mask ^= (1 << i);
                u = i;
                break;
            }
        }
        dfs(mask, u, tmp);
        cout << "Case " << icase++ << ": " << Myans << endl;
    }
    return 0;
}
