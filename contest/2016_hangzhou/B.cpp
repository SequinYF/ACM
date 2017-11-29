/********************************************************************
* File Name: B.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 二 10/24 10:21:01 2017
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

#define lson 2*i
#define rson 2*i+1
#define LS l,mid,lson
#define RS mid+1,r,rson
#define UP(i,x,y) for(i=x;i<=y;i++)
#define DOWN(i,x,y) for(i=x;i>=y;i--)
#define MEM(a,x) memset(a,x,sizeof(a))
#define W(a) while(a)
#define gcd(a,b) __gcd(a,b)
#define pi acos(-1.0)
#define pii pair<ll,ll>
#define ll long long
#define MAX 1005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define lowbit(x) (x&-x)
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}

struct node{
    int c;
    ll r;
    ll x, y;
}node[MAX];

vector<int> G[MAX];
stack<int> S;
int pre[MAX], sccno[MAX], low[MAX], dfs_clock, scc_cnt;
int in0[MAX], ret[MAX];

void dfs(int u) {
    pre[u] = low[u] = ++dfs_clock;
    S.push(u);
    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(!pre[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else if(!sccno[v]) {
            low[u] = min(pre[v], low[u]);
        }
    }

    if(pre[u] == low[u]) {
        scc_cnt++;
        while(1) {
            int x = S.top();
            S.pop();
            sccno[x] = scc_cnt;
            if(x == u) break;
        }
    }
}

void tarjan(int n) {
    MEM(pre, 0);
    MEM(sccno, 0);
    dfs_clock = scc_cnt = 0;
    for(int i = 1; i <= n; i++) {
        if(!pre[i]) {
            dfs(i);
        }
    }
}


int main(){
    int T, t;
    cin >> T;
    UP(t, 1, T) {
        int ans = 0, n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            ret[i] = INF;
            G[i].clear();
            cin >> node[i].x >> node[i].y >> node[i].r >> node[i].c;
        }
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                if(i != j) {
                    ll xx = node[i].x - node[j].x;
                    ll yy = node[i].y - node[j].y;
                    ll dis = xx * xx + yy * yy;
                    ll rr = node[i].r * node[i].r;
                    if(dis <= (rr)) {
                        G[i].push_back(j);
                    }
                }
            }
        }

        tarjan(n);

        for(int i = 1; i <= scc_cnt; i++) {
            in0[i] = 0;
        }

        for(int u = 1; u <= n; u++) {
            for(int i = 0; i < G[u].size(); i++) {
                int v = G[u][i];
                if(sccno[v] != sccno[u]) {
                    in0[sccno[v]]++;
                }
            }
        }

        for(int i = 1; i <= n; i++) {
            if(!in0[sccno[i]]) {
                ret[sccno[i]] = min(ret[sccno[i]], node[i].c);
            }
        }

        for(int i = 1; i <= scc_cnt; i++) {
            if(!in0[i]) {
                ans += ret[i];
            }
        }

        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
