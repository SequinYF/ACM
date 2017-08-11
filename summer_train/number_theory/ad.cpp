/********************************************************************
* File Name: ad.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 五  8/11 21:12:49 2017
*************************************************************************/

#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int exgcd(int a, int b, int &x, int &y) {
	if(b == 0) {
		x = 1; y = 0;
		return a;
	}
	int ret = exgcd(b, a%b, x, y);
	int t = x;
	x = y;
	y = t - a/b*y;

	return ret;
}

int solve(int a, int b, int n) {
	int d = __gcd(b, n);
	//cout << d << endl;
	if(a % d != 0) return -1;
	int k = a / d;
	int x, y;
	exgcd(b, n, x, y);

	return x * k;
}

int main() {
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--) {
		int n, b;
		cin >> n >> b;
		int x, y;
		
		int t = solve(n, b, 9973);

	t = (9973 + t % 9973) % 9973;

		cout << t << endl;
	}
}