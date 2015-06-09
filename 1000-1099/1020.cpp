/*************************************************************************
    > File Name: LightOJ1020.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月09日 星期二 18时46分32秒
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
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int n;
        string s;
        cin >> n >> s;
        n %= 3;
        cout << "Case " << icase++ << ": ";
        if (s[0] == 'A') {
            if (n == 1) {
                printf("Bob\n");
            }
            else {
                printf("Alice\n");
            }
        }
        else {
            if (n == 0) {
                printf("Alice\n");
            }
            else {
                printf("Bob\n");
            }
        }
    }
    return 0;
}
