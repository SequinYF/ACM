/********************************************************************
* File Name: yuanxingshizihebing.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 四  8/10 22:18:55 2017
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define INF 0x7FFFFFFF
#define ll long long

int dp_max[2000][2000];
int dp_min[2000][2000];
int stone[2000];
int sum[2000];

int main() {
	int n, add = 0;
	cin >> n;

	for(int i = 1; i <= n; i++) {
		cin >> stone[i];
		add += stone[i];
		sum[i] = add;
	}

	for(int i = n+1; i <= 2*n; i++) {
		stone[i] = stone[i-n];
		add += stone[i];
		sum[i] = add;
	}

	// for(int i = 1; i <= 2*n; i++) {
	// 	cout << stone[i] <<" " <<sum[i] << endl;
	// }

	memset(dp_min, 0, sizeof(dp_min));
	memset(dp_max, 0, sizeof(dp_max));
	sum[0] = 0;
	sum[2*n+1] = 0;

	for(int len = 2; len <= n*2; len++) {
		for(int i = 1; i + len <= n*2+1; i++) {
			int e = len + i - 1;
			dp_min[i][e] = INF;
			for(int j = i; j < e; j++) {
				add = sum[e] - (i == 0 ? 0 : sum[i-1]);
				dp_min[i][e] = min(dp_min[i][e], dp_min[i][j] + dp_min[j+1][e] + add);
				dp_max[i][e] = max(dp_max[i][e], dp_max[i][j] + dp_max[j+1][e] + add);
			}
		}
	}

	int temp_max = -INF;
	int temp_min = INF;
	for(int i = 1; i <= n; i++) {
		temp_max = max(dp_max[i][n+i-1], temp_max);
		temp_min = min(dp_min[i][n+i-1], temp_min);
	}

	cout << temp_min << endl;
	cout << temp_max << endl;

}