/********************************************************************
* File Name: 9999.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 日  9/17 14:30:43 2017
*************************************************************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <ctype.h>
#include <set>
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <climits>
#include <string>
#include <list>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

const int N = 501;
const int MAXV = 0x3F3F3F3F;
int n,m,v[N];//经过合并后的第i个节点v[i]
int mat[N][N];
int dis[N];//dis[i]表示w(A,v[i])
bool vis[N];
int res;
inline int min(int a, int b){
    return a < b ? a : b;
}
int Stoer_Wagner(int n, int s, int t) {
    int i, j;
    int res = MAXV;
    for (i = 0; i < n; i++)
        v[i] = i;//初始化第i个结点就是i
    while (n > 1) {
        int maxp = 1,prev = 0;
        for (i = 1;i < n;i++){ //初始化到已圈集合的割大小,并找出最大距离的顶点
            dis[v[i]] = mat[v[0]][v[i]];
            if (dis[v[i]] > dis[v[maxp]])
                maxp = i;
        }
        memset(vis, 0, sizeof(vis));
        vis[v[0]] = true;
        for (i = 1;i < n;i++) {
            if (i == n - 1){ //只剩最后一个没加入集合的点，更新最小割
                res = min(res,dis[v[maxp]]);
                for (j = 0; j < n; j++){ //合并最后一个点以及推出它的集合中的点
                    mat[v[prev]][v[j]] += mat[v[j]][v[maxp]];
                    mat[v[j]][v[prev]] = mat[v[prev]][v[j]];
                }
                v[maxp] = v[--n];//第maxp个节点去掉，第n个节点变成第maxp个
            }
            vis[v[maxp]] = true;
            prev = maxp;
            maxp = -1;
            for (j = 1;j < n;j++)
                if (!vis[v[j]]){ //将上次求的maxp加入集合，合并与它相邻的边到割集
                    dis[v[j]] += mat[v[prev]][v[j]];
                    if (maxp == -1 || dis[v[maxp]] < dis[v[j]])
                        maxp = j;
                }
        }
    }
    return res;
}
int main(){
	int T;
	scanf("%d", &T);
    while (T--) {
    	scanf("%d%d", &n, &m);
        memset(mat, 0, sizeof (mat));
        int x,y,z;
        int s, t;
        scanf("%d%d", &s,&t);
        while (m--) {
            scanf("%d%d%d", &x, &y, &z);
            mat[x][y] += z;
            mat[y][x] += z;
        }
        printf("%d\n",Stoer_Wagner(n, s, t));
    }
    return 0;
}
