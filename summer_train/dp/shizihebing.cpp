/********************************************************************
* File Name: shizihebing.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 三  8/ 9 23:26:25 2017
*************************************************************************/
#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;
#define INF 0x3f3f3f3f
int sum[1002];
int dp_min[1002][1002];
int dp_max[1002][1002];
int stone[1002];

int main() {
	int n;
	while (cin >> n) {
		int add = 0;
		for (int i = 1; i <= n; i++)	{
			cin >> stone[i];
			add += stone[i];
			sum[i] = add;
		}

		memset(dp_min, 0, sizeof(dp_min));
		memset(dp_max, 0, sizeof(dp_max));
		sum[0] = 0;

		for (int k = 1; k < n; k++)
			for (int i = 1; i + k <= n; i++) {
				int t = k + i;
				dp_min[i][t] = INF;
				for (int j = i; j < t; j++) {
					add = sum[t] - (i == 0 ? 0 : sum[i-1]);
					dp_min[i][t] = min(dp_min[i][t], dp_min[i][j]+dp_min[j+1][t]+add);
					dp_max[i][t] = max(dp_max[i][t], dp_max[i][j]+dp_max[j+1][t]+add);
				}

			}

		cout << dp_min[1][n] << " " << dp_max[1][n] << endl;
	}
}