/********************************************************************
* File Name: a.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 五  8/25 00:06:26 2017
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio.h>
#include <cmath>

int dir[2][4] = {1, 0, 0, 1, -1, 0, 0, -1};
int vis[maxn][maxn];

int dfs(string mm[], int i, int j, char flag) {

	if(mm[i][j] != flag) {
		return;
	}

	for(int ii = 0; ii <= 3; ii++) {
		int x = i;
		int y = j;

		x += dir[ii][0];
		y += dir[ii][1];

		if(!vis[x][y] && x > 0 && y > 0 && x <= m && y <= n && mm[x][j] == flag) {
			vis[x][y] = 1;
			dfs(mm, x, y, flag);
			vis[x][y] = 0;
		}
	}


}





int main() {
	int n, m;
	while(cin >> n >> m) {
		string mm[n+1];
		for(int i = 0; i <= n; i++) {
			cin >> mm[i];
		}
		
		memset(vis, 0, sizeof(vis));
		int num1, num0;
		num0 = num1 = 0;

		for(int i = 0; i <= m; i++) {
			for(int j = 0; j <= n; j++) {
				if(mm[i][j] == '0' && !vis[i][j]) {
					dfs(mm, i, j, '0');
					num0++;
				}
				if(mm[i][j] == '1' && !vis[i][j]) {
					dfs(mm, i, j, '1');
					num1++;
				}
			}
		}

		if(num1 > 1) {
			cout << -1 << endl;
		}
		else if(num1 == 1 && num0 == 1) {
			cout << 1 << endl;
		}
		else if(num1 == 1 && num0 == 2)	{
			cout << 0 << endl;
		}
	}

	return 0;
}