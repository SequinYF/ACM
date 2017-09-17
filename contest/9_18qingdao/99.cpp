/********************************************************************
 * File Name: 99.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 日  9/17 13:26:09 2017
 *************************************************************************/


#include<iostream>
#include<stdio.h>
#include<math.h>
#include <string>
#include<string.h>
#include<map>
#include<queue>
#include<set>
#include<utility>
#include<vector>
#include<algorithm>
#include<stdlib.h>
using namespace std;
#define maxn 1005
#define maxm 100005
#define rd(x) scanf("%d", &x)
#define rd2(x, y) scanf("%d%d", &x, &y)

const int INF = 0x3f3f3f3f;
struct Edge{
    int to, next, cap, flow;
}edge[maxm];
int tol, head[maxn];
int gap[maxn], dep[maxn], pre[maxn], cur[maxn];
void init(){
    tol = 0;
    memset(head, -1, sizeof(head));
}
void addedge(int u, int v, int w, int rw = 0){
    edge[tol].to = v; edge[tol].cap = w; edge[tol].next = head[u];
    edge[tol].flow = 0; head[u] = tol++;
    edge[tol].to = u; edge[tol].cap = rw; edge[tol].next = head[v];
    edge[tol].flow = 0; head[v] = tol++;
}
int sap(int st, int ed, int N){
    memset(gap, 0 ,sizeof(gap));
    memset(dep, 0 ,sizeof(dep));
    memcpy(cur, head, sizeof(head));
    int u = st;
    pre[u] = -1;
    gap[0] = N;
    int ans = 0;
    while(dep[st] < N){
        if(u == ed){
            int Min = INF;
            for(int i = pre[u]; i != -1; i = pre[edge[i^1].to])
                if(Min > edge[i].cap - edge[i].flow)
                    Min = edge[i].cap - edge[i].flow;
            for(int i = pre[u]; i != -1; i = pre[edge[i^1].to]){
                edge[i].flow += Min;
                edge[i^1].flow -= Min;
            }
            u = st;
            ans += Min;
            continue;
        }
        bool flag = false;
        int v;
        for(int i = cur[u]; i != -1; i = edge[i].next){
            v = edge[i].to;
            if(edge[i].cap - edge[i].flow && dep[v] + 1 == dep[u]){
                flag = true;
                cur[u] = pre[v] = i;
                break;
            }
        }
        if(flag){
            u = v;
            continue;
        }
        int Min = N;
        for(int i = head[u]; i!= -1; i = edge[i].next){
            if(edge[i].cap - edge[i].flow && dep[edge[i].to] < Min){
                Min = dep[edge[i].to];
                cur[u] = i;
            }
        }
        gap[dep[u]]--;
        if(!gap[dep[u]]) return ans;
        dep[u] = Min + 1;
        gap[dep[u]]++;
        if(u != st) u = edge[pre[u]^1].to;
    }
    return ans;
}
/*求最小割集*/
set<int> sset;
int lvl[maxn];
void bfs(int s, int t){
    queue<int> q;
    memset(lvl, 0 ,sizeof(lvl));
    q.push(s);
    lvl[s] = 1;
    while(!q.empty()){
        int u = q.front();
        sset.insert(u);
        q.pop();
        for(int i = head[u]; i != -1; i = edge[i].next){
            int v = edge[i].to;
            if(lvl[v] == 0 && edge[i].cap > edge[i].flow){
                lvl[v] = lvl[u] + 1;
                /*这里edge[i]就是最小割里的边了*/
                q.push(v);
            }
        }
    }
}

int main()
{
    int T;
    rd(T);
    while(T--)
    {
        int n, m, a, b, c;
        int s,t;
        init();
        rd2(n, m);
        rd2(s, t);
        for(int i = 1; i <= m; i++){
            int mm[n+1][n+1];
            scanf("%d%d%d", &a, &b, &c);
            addedge(a,b,c);
        }
        int maxflow = sap(s, t, n);
        bfs(s, t);
        cout << maxflow << endl;
        cout << sset.size() << endl;

    }
    return 0;
}

