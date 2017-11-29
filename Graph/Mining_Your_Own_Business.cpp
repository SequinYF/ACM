/********************************************************************
 * File Name: Mining_Your_Own_Business.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 五  9/22 20:05:59 2017
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
#define pii pair<int,int>
#define ll long long
#define MAX 10000005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define lowbit(x) (x&-x)
#define maxn 100005
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}

struct Edge{
    int u, v;
};

int pre[maxn], iscut[maxn], bccno[maxn], dfs_clock, bcc_cnt;
vector<int> G[maxn], bcc[maxn];
stack<Edge> S;

int dfs(int u, int fa) {
    int lowu = pre[u] = ++dfs_clock;
    int child = 0;

    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        Edge e = (Edge) {u, v};
        if(!pre[v]) {
            S.push(e);
            child++;
            int lowv = dfs(v, u);
            lowu = min(lowv, lowu);
            if(lowv >= pre[u]) {
                bcc_cnt++;
                bcc[bcc_cnt].clear();
                iscut[u] = true;

                W(1) {
                    Edge x = S.top();
                    S.pop();
                    if(bccno[x.u] != bcc_cnt) {
                        bcc[bcc_cnt].push_back(x.u);
                        bccno[x.u] = bcc_cnt;
                    }
                    if(bccno[x.v] != bcc_cnt) {
                        bcc[bcc_cnt].push_back(x.v);
                        bccno[x.v] = bcc_cnt;
                    }
                    if(x.u == u && x.v == v){
                        break;
                    }
                }
            }
        }
        else if(pre[v] < pre[u] && v != fa) {
            S.push(e);
            lowu = min(pre[v], lowu);
        }
    }
    if(fa  < 0 && child == 1) {
        iscut[u] = 0;
    }
    return lowu;
}


void find_bcc(int N) {
    MEM(pre, 0);
    MEM(iscut, 0);
    MEM(bccno, 0);
    dfs_clock = 0;
    bcc_cnt = 0;
    for(int i = 1; i <= N; i++) {
        if(!pre[i]){
            dfs(i, -1);
        }
    }
}

int mm[100005][2];
int main() {
    std::ios::sync_with_stdio(false);
    int n;
    int T = 0;
    while(cin >> n && n) {
        T++;
        int maxnum = 0;
        MEM(mm, 0);
        for(int i = 0; i < n; i++) {
            int a, b;
            cin >> a >> b;
            mm[i][0] = a; mm[i][1] = b;
            a = max(a, b);
            maxnum = max(a, maxnum);
        }
        for(int i = 1; i <= maxnum; i++) {
            G[i].clear();
        }

        for(int i = 0; i < n; i++){

            int a = mm[i][0];
            int b = mm[i][1];
            G[a].push_back(b);
            G[b].push_back(a);
        }



        find_bcc(maxnum);
        ll ret = 0;
        ll ans = 1;

        for(int i = 1; i <= bcc_cnt; i++) {
            int cut_cnt = 0;
            for(int j = 0; j < bcc[i].size(); j++) {
                if(iscut[bcc[i][j]]) {
                    cut_cnt++;
                }
            }

            if(cut_cnt == 1) {
                ret++;
                ans *= (ll)(bcc[i].size() - cut_cnt);
            }
        }
        if(bcc_cnt == 1) {
            ret = 2;
            ans = maxnum * (maxnum - 1) / 2;
        }
        cout << "Case " << T << ": ";
        cout << ret << " " << ans << endl;
    }
}
