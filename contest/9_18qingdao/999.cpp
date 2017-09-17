/********************************************************************
* File Name: 999.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 日  9/17 13:31:04 2017
*************************************************************************/


#include <iostream>
#include <cstdio>
#include <string>
#include <cstring>
#include <cmath>
#include <stack>
#include <queue>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <stdlib.h>
#include <iomanip>
#include <fstream>

using namespace std;
#pragma comment(linker, "/STACK:102400000,102400000")
#define maxn 505
#define MOD 1000000007
#define mod 2147493647
#define mem(a , b) memset(a , b , sizeof(a))
#define LL long long
#define ULL unsigned long long
#define FOR(i , n) for(int i = 1 ;  i<= n ; i ++)
typedef pair<int , int> pii;
int n , m , t;
vector<int>V[maxn];
int a[maxn][maxn] , path[maxn];
bool vis[maxn] ;
int flow[maxn];

bool GetAugmentPath()
{
    queue<int>q;
    while(!q.empty()) q.pop();
    q.push(1);vis[1] = 1;
    flow[1] = MOD;
    while(!q.empty())
    {
        int cur = q.front();
        q.pop();
        if(cur == n)
        {
            return 1;
        }
        for(int i = 0 ; i < V[cur].size() ; i ++)
        {
            if(!vis[V[cur][i]] && a[cur][V[cur][i]] > 0)
            {
                vis[V[cur][i]] = 1;
                path[V[cur][i]] = cur;
                flow[V[cur][i]] = min(a[cur][V[cur][i]] , flow[cur]);
                q.push(V[cur][i]);

            }
        }
    }
    return 0;
}

void Update(int num)
{
    int u = n , v = path[u];
    while(v != -1)
    {
        a[v][u] -= num;
        a[u][v] += num;
        u = v;
        v = path[u];
    }
    return ;
}

int main()
{
    //scanf("%d" , &t);
    int ncase = 1;
    while(scanf("%d %d" , &n , &m) != EOF)
    {

        for(int i = 0 ; i <= n ; i ++) V[i].clear();
        mem(a , 0);mem(vis , 0);mem(path , -1);mem(flow , 0);
        int u , v , c ;
        for(int i = 0 ; i < m ; i ++)
        {
            scanf("%d %d %d" , &u , &v , &c);
            a[u][v] += c ;
          //  a[v][u] = max(0 , a[v][u]);
            V[u].push_back(v);
            V[v].push_back(u);
        }
        int ans = 0;
        while(GetAugmentPath())
        {
            ans += flow[n];
            Update(flow[n]);
            mem(vis , 0);mem(path , -1);mem(flow , 0);
        }
        int Node[maxn] , id = 0;
        for(int i = 1 ; i <= n ; i ++)
        {
            if(vis[i])
            {
                Node[id++] = i;
            }
        }
        printf("%d %d\n" , ans , id);
        for(int i = 0 ; i < id; i ++)
        {
            printf("%d" , Node[i]);
            if(i != id - 1) printf(" ");
          //  else printf("%d\n");
        }
        cout << endl;
    }
    return 0;
}

