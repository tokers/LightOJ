/*************************************************************************
    > File Name: LightOJ1024.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年06月17日 星期三 20时34分30秒
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


struct BigInt
{
    const static int mod = 10000;
    const static int DLEN = 4;
    int a[1600],len;
    BigInt()
    {
        memset(a,0,sizeof(a));
        len = 1;
    }
    BigInt(int v)
    {
        memset(a,0,sizeof(a));
        len = 0;
        do
        {
            a[len++] = v%mod;
            v /= mod;
        }
        while(v);
    }
    BigInt(const char s[])
    {
        memset(a,0,sizeof(a));
        int L = strlen(s);
        len = L/DLEN;
        if(L%DLEN)len++;
        int index = 0;
        for(int i = L-1; i >= 0; i -= DLEN)
        {
            int t = 0;
            int k = i - DLEN + 1;
            if(k < 0)k = 0;
            for(int j = k; j <= i; j++)
                t = t*10 + s[j] - '0';
            a[index++] = t;
        }
    }
    BigInt operator +(const BigInt &b)const
    {
        BigInt res;
        res.len = max(len,b.len);
        for(int i = 0; i <= res.len; i++)
            res.a[i] = 0;
        for(int i = 0; i < res.len; i++)
        {
            res.a[i] += ((i < len)?a[i]:0)+((i < b.len)?b.a[i]:0);
            res.a[i+1] += res.a[i]/mod;
            res.a[i] %= mod;
        }
        if(res.a[res.len] > 0)res.len++;
        return res;
    }
    BigInt operator *(const BigInt &b)const
    {
        BigInt res;
        for(int i = 0; i < len; i++)
        {
            int up = 0;
            for(int j = 0; j < b.len; j++)
            {
                int temp = a[i]*b.a[j] + res.a[i+j] + up;
                res.a[i+j] = temp%mod;
                up = temp/mod;

            }
            if(up != 0)
                res.a[i + b.len] = up;
        }
        res.len = len + b.len;
        while(res.a[res.len - 1] == 0 &&res.len > 1)res.len--;
        return res;
    }
	
	BigInt operator * (const int &b) const {
		BigInt res;
		int up = 0;
		for (int i = 0; i < len; ++i) {
			int tmp = a[i] * b + up;
			res.a[i] = tmp % mod;
			up = tmp / mod;
		}
		if (up) {
			res.a[len] = up;
		}
		res.len = len + 1;
		while (res.a[res.len - 1] == 0 && res.len > 1) {
			--res.len;
		}
		return res;
	}

    void output()
    {
        printf("%d",a[len-1]);
        for(int i = len-2; i >=0 ; i--)
            printf("%04d",a[i]);
        printf("\n");
    }
};

int Arr[10010];

int main() {
	int t, icase = 1;
	scanf("%d", &t);
	while (t--) {
		for (int i = 1; i <= 10000; ++i) {
			Arr[i] = 0;
		}
		int n;
		int now;
		scanf("%d", &n);
		for (int i = 1; i <= n; ++i) {
			scanf("%d", &now);
			for (int j = 2; j * j <= now; ++j) {
				if (now % j == 0) {
					int cnt = 0;
					while (now % j == 0) {
						now /= j;
						++cnt;
					}
					Arr[j] = max(Arr[j], cnt);
				}
			}
			if (now > 1) {
				Arr[now] = max(Arr[now], 1);
			}
		}
		BigInt ans("1");
		for (int i = 1; i <= 10000; ++i) {
			if (Arr[i]) {
				for (int j = 1; j <= Arr[i]; ++j) {
					ans = ans * i;
				}
			}
		}
		printf("Case %d: ", icase++);
		ans.output();
	}
	return 0;
}
