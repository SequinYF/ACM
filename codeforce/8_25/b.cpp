/********************************************************************
* File Name: b.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 五  8/25 00:59:07 2017
*************************************************************************/


#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

int tab[51][51];
int n, m;
int row1[51], row0[51], col1[51], col0[51];
//C（m,r）=m!/(r!*(m-r))

long long fun(int m, int r) {
	long long mm, rr;
	mm = rr = 1;
	if(m == r) {
	//	cout << m << r << endl;
		return 1;
	}
	if(m < r) return 0;
	for(int i = 1; i <= m; i++) {
		mm *= i;
	
	}
	for(int j = 1; j <= r; j++) {
			rr *= j;
	}
	//cout << m <<  r << mm /(rr * (m-r)) << endl;
	return mm /(rr * (m-r));
}

int main() {
	int n, m;
	cin >> n >> m;

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			cin >> tab[i][j];
		}
	}

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= m; j++) {
			if(tab[i][j] == 1){
				row1[i]++;
				col1[j]++;
			}
			else if(tab[i][j] == 0) {
				row0[i]++;
				col0[j]++;
			}
		}
	}

	int coun = max(n, m);
	long long ret = 0;

	for(int i = 1; i <= n; i++) {
		for(int j = 2; j <= m; j++) {
			ret += fun(row1[i], j);
			ret += fun(row0[i], j);
		}	
		//cout << ret << endl;	
	}
	for(int j = 1; j <= m; j++) {
		//cout << col0[j] << endl;
		for(int k = 2; k <= n; k++) {
			ret += fun(col1[j], k);
			ret += fun(col0[j], k);
		}
	}

	cout << ret + n * m<< endl;
}