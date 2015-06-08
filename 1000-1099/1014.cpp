/*************************************************************************
    > File Name: LightOJ1014.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com
    > Created Time: 2015年06月08日 星期一 17时50分45秒
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
 
vector <int> fac;
 
int main() {
    int t, icase = 1;
    scanf("%d", &t);
    while (t--) {
        int P, L;
        fac.clear();
        scanf("%d%d", &P, &L);
        for (LL i = 1; i * i <= P - L; ++i) {
            if ((P - L) % i == 0) {
                if (i > L) {
                    fac.push_back(i);
                }
                if ((P - L) / i != i) {
                    if ((P - L) / i > L) {
                        fac.push_back((P - L) / i);
                    }
                }
            }
        }
        sort(fac.begin(), fac.end());
        printf("Case %d:", icase++);
        int size = fac.size();
        if (!size) {
            printf(" impossible\n");
            continue;
        }
        for (int i = 0; i < size; ++i) {
            printf(" %d", fac[i]);
        }
        printf("\n");
    }
    return 0;
}
