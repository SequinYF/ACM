/********************************************************************
* File Name: huaxue.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 六  8/12 22:24:08 2017
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define INF 0x7FFFFFFF
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int snow[101][101];
int dp[200][200];
int r, c;




bool check(int i, int j, int value) {
	if(i < 0 || j < 0 || i >= r || j >= c)	return false;

	if(value <= snow[i][j])	return false;

	return true;
}



int dfs(int i, int j) {
	if(dp[i][j] >= 0)	return dp[i][j];

	int ret = 0;
	for(int d = 0; d < 4; d++) {
		int x = dir[d][0] + i;
		int y = dir[d][1] + j;
		if(check(x, y, snow[i][j])) {
			ret = max(dfs(x, y) + 1, ret);
		}
	}

	if(!ret) ret = 1;
	
	dp[i][j] = ret;
	return ret;
}


int main() {

	cin >> r >> c;
	int x, y;
	int MAX = -INF;
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			cin >> snow[i][j];
		}
	}

	memset(dp, -1, sizeof(dp));
	for(int i = 0; i < r; i++) {
		for(int j = 0; j < c; j++) {
			MAX = max(dfs(i, j), MAX);	
		}
	}

	cout << MAX << endl;
	return 0;
}