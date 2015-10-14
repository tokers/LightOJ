/*************************************************************************
    > File Name: LightOJ1309.cpp
    > Author: ALex
    > Mail: zchao1995@gmail.com 
    > Created Time: 2015年10月14日 星期三 20时26分48秒
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

stack <char> ope;
queue <int> qu;
stack < pair <LL, LL> > work;
string str;

void pushqueue(char c) {
	if (c == '+') {
		qu.push(-1);
	}
	else if (c == '*') {
		qu.push(-3);
	}
	else if (c == '-') {
		qu.push(-2);
	}
	else {
		qu.push(-4);
	}
}

void debug() {
	while (!qu.empty()) {
		int now = qu.front();
		qu.pop();
		if (now >= 0) {
			cout << now << " ";
		}
		else {
			if (now == -1) {
				cout << "+ ";
			}
			else if (now == -2) {
				cout << "- ";
			}
			else if (now == -3) {
				cout << "* ";
			}
			else {
				cout << "x ";
			}
		}
	}
	cout << endl;
}

pair <LL, LL> go(string str) {
	while (!ope.empty()) {
		ope.pop();
	}
	while (!qu.empty()) {
		qu.pop();
	}
	while (!work.empty()) {
		work.pop();
	}
	int len = str.length(), now = 0;
	while (now < len) {
		if (str[now] >= '0' && str[now] <= '9') {
			int num = 0;
			while (now < len && str[now] >= '0' && str[now] <= '9') {
				num = num * 10 + str[now++] - '0';
			}
			qu.push(num);
		}
		else if (str[now] == 'x') {
			pushqueue(-4);
			++now;
		}
		else {
			if (str[now] == '(') {
				ope.push('(');
			}
			else {
				if (str[now] == ')') {
					while (!ope.empty()) {
						char c = ope.top();
						ope.pop();
						if (c == '(') {
							break;
						}
						else {
							pushqueue(c);
						}
					}
				}
				else {
					bool flag = 0;
					while (!ope.empty()) {
						char c = ope.top();
						if (c == '(') {
							ope.push(str[now]);
							flag = 1;
							break;
						}
						if ((c == '+' || c == '-') && str[now] == '*') {
							flag = 1;
							ope.push(str[now]);
							break;
						}
						else {
							ope.pop();
							pushqueue(c);
						}
					}
					if (!flag) {
						ope.push(str[now]);
					}
				}
			}
			++now;
		}
	}
	while (!ope.empty()) {
		pushqueue(ope.top());
		ope.pop();
	}
	while (!qu.empty()) {
		int x = qu.front();
		qu.pop();
		if (x >= 0 || x == -4) {
			if (x >= 0) {
				work.push(make_pair(0, x));
			}
			else {
				work.push(make_pair(1, 0));
			}
		}
		else {
			pair <LL, LL> op2 = work.top();
			work.pop();
			pair <LL, LL> op1 = work.top();
			work.pop();
			if (x == -3) {
				work.push(make_pair((LL)op1.first * op2.second + (LL)op1.second * op2.first, (LL)op1.second * op2.second));
			}
			else {
				int sgn = 1;
				if (x == -2) {
					sgn = -1;
				}
				work.push(make_pair((LL)op1.first + sgn * op2.first, (LL)op1.second + sgn * op2.second));
			}
		}
	}
	return work.top();
}

int main() {
	int t, icase = 1;
	cin >> t;
	while (t--) {
		cin >> str;
		string s1, s2;
		int len = str.length();
		for (int i = 0; i < len; ++i) {
			if (str[i] == '=') {
				s1 = str.substr(0, i);
				s2 = str.substr(i + 1, len - i - 1);
				break;
			}
		}
		pair <LL, LL> l = go(s1);
		pair <LL, LL> r = go(s2);
		cout << "Case " << icase++ << ": ";
		if (l.first == r.first) {
			if (l.second != r.second) {
				cout << "no solution" << endl;
			}
			else {
				cout << "infinitely many solutions" << endl;
			}
		}
		else {
			int a = l.first - r.first;
			int b = r.second - l.second;
			int gcd = __gcd(a, b);
			if(b % a == 0) {
				cout << b / a << endl;
			}
			else {
				if ((LL)a * b < 0) {
					cout << "-";
				}
				cout << abs(b / gcd) << "/" << abs(a / gcd) << endl;
			}
		}
	}
	return 0;
}
