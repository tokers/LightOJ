    /*************************************************************************
        > File Name: LightOJ1000.cpp
        > Author: ALex
        > Mail: zchao1995@gmail.com
        > Created Time: 2015年06月02日 星期二 19时18分41秒
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
        int a, b;
        int t, icase = 1;
        cin >> t;
        while (t--) {
            cin >> a >> b;
            cout << "Case " << icase++ << ": " << a + b << endl;
        }
        return 0;
    }

