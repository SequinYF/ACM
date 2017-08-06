/********************************************************************
* File Name: Tempter_of_the_Bone.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 六  8/ 5 15:46:07 2017
*************************************************************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
bool vis[10][10];
int n, m, t;
bool flag;

struct node{
	int x, y;
};
node s, e;

bool check(int x, int y){
	if(x >= n || x < 0 || y >= m || y < 0)
		return 0;

	return 1;
}
void dfs(int x, int y, int depth){
	if(flag || depth > t){
		return;
	}
	if(x == e.x && y == e.y){
		if(depth == t){
			puts("YES");
			flag = true;
		}
		return;
	}

	//剪枝
	int rest = abs(x - e.x) + abs(y - e.y);
	if(t-depth < rest || (t-depth+rest)%2){
		return;
	}

	for(int i = 0; i < 4; i++){
		int xx = x + dir[i][0];
		int yy = y + dir[i][1];
		if(check(xx, yy) && vis[xx][yy]){
			vis[xx][yy] = 0;
			dfs(xx, yy, depth+1);
			vis[xx][yy] = 1;
		}
	}
}

int main()
{
	while(~scanf("%d%d%d", &n, &m, &t) && n + m + t){
		s.x = s.y = e.x = e.y = -1;
		string maze;
		flag = false;
		int coun_x = 0;
		for(int i = 0; i < n; i++){
			cin >> maze;
			for(int j = 0; j < m; j++){
				char ch = maze[j];
				if(ch == 'S'){
					s.x = i; s.y = j;
					vis[i][j] = 0;
				}
				if(ch == 'D'){
					e.x = i; e.y = j;
					vis[i][j] = 1;
				}
				if(ch == '.')
					vis[i][j] = 1;
				if(ch == 'X'){
					vis[i][j] = 0;
					coun_x++;
				}
			}
		}
		if(n * m - coun_x - 1 < t){ //剪枝
			puts("NO");
			continue;
		}
		dfs(s.x, s.y, 0);
		if(!flag)
			puts("NO");
	}
}

