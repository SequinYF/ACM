/********************************************************************
 * File Name: Proving_Equivalences.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 一 10/23 20:35:51 2017
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
#define MAX 20005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define lowbit(x) (x&-x)
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}

vector<int> G[MAX];
int pre[MAX], low[MAX], sccno[MAX], in0[MAX], out0[MAX], dfs_clock, scc_cnt;
stack<int> S;

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
            low[u] = min(low[u], pre[v]);
        }
    }

    if(pre[u] == low[u]) {
        scc_cnt++;
        while(1){
            int x = S.top();
            S.pop();
            sccno[x] = scc_cnt;
            if(x == u) break;
        };
    }
}



void tarjan(int n) {
    MEM(sccno, 0);
    MEM(pre, 0);
    dfs_clock = scc_cnt = 0;
    for(int i = 0; i < n; i++) {
        if(!pre[i])
            dfs(i);
    }
}

int main() {
    int T, n, m;
    cin >> T;
    while(T--) {
        cin >> n >> m;
        for(int i = 0; i < n; i++) G[i].clear();
        for(int i = 0; i < m; i++) {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            G[u].push_back(v);
        }

        tarjan(n);

        for(int i = 1; i <= scc_cnt; i++) {
            in0[i] = out0[i] = 1;
        }
        for(int u = 0; u < n; u++) {
            for(int i = 0; i < G[u].size(); i++) {
                int v = G[u][i];
                if(sccno[v] != sccno[u]){
                    in0[sccno[v]] = 0;
                    out0[sccno[u]] = 0;
                }
            }
        }

        int a = 0, b = 0;
        for(int i = 1; i <= scc_cnt; i++) {
            if(in0[i]) a++;
            if(out0[i]) b++;
        }

        int ret = max(a, b);
        if(scc_cnt == 1)
            ret = 0;

        cout << ret << endl;
    }
}
