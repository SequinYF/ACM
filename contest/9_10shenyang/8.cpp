/********************************************************************
* File Name: 8.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 一  9/11 15:43:47 2017
*************************************************************************/
#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <vector>
using namespace std;

#define N 100001

typedef struct node {
    int to, co;
}node;

int cost[N];
int now[N];
bool vis[N];
vector <node> pa[N];

int dfs(int t) {
    if(vis[t])    return cost[t];
    vis[t] = 1;
    for(int i = 0; i < pa[t].size(); i++) {
        cost[t] = min(cost[t], pa[t][i].co+dfs(pa[t][i].to));
    }
    return cost[t];
}


int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);

        for(int i = 1; i <= n; i++){
            scanf("%d", &cost[i]);
        }
        for(int i = 1; i < n; i++) {
            int x, y, z;
            scanf("%d%d%d", &x, &y, &z);
           // pa[x].push_back(node{y,z});
           // pa[y].push_back(node{x,z});
           node tmp;
           tmp.to = x;
           tmp.co = z;
           pa[y].push_back(tmp);
           tmp.to = y;
           pa[x].push_back(tmp);
        }
        memcpy(now, cost, sizeof(cost));
        memset(vis, 0, sizeof(vis));
        dfs(1);
        int ret = 0;
        for(int i = 1; i <= n; i++) {
            ret = max(ret, now[i] - cost[i]);
        }

        printf("%d\n", ret);
    }
}
