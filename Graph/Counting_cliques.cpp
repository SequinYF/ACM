/********************************************************************
 * File Name: Counting_cliques.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 四 10/26 22:06:24 2017
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
#define MAX 105
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define lowbit(x) (x&-x)
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}
int n, m ,s;
int res;
bool mmap[MAX][MAX];
vector<int> G[MAX];
set<int> S;
set<int>::iterator iter;
bool vis[MAX];

bool check(int v) {
    for(iter = S.begin(); iter != S.end(); iter++) {
        if(!mmap[*iter][v]){
            return false;
        }
    }
    return true;
}


void dfs(int u, int now) {
    if(now >= s) {
        res++;
        S.clear();
        return;
    }

    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(check(v) && !vis[v]) {
            vis[v] = 1;
            S.insert(v);
            dfs(v, now+1);
            S.erase(v);
            vis[v] = 0;
        }
    }
}


int main() {
    int T;
    ios::sync_with_stdio(false);
    cin >> T;
    while(T--) {
        cin >> n >> m >> s;
        MEM(mmap, 0);
        for(int i = 1; i <= n; i++) {
            vis[i] = 0;
            G[i].clear();
        }
        res = 0;
        S.clear();
        for(int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            mmap[a][b] = 1;
            mmap[b][a] = 1;
            G[a].push_back(b);

        }
        for(int i = 1; i <= n; i++){
            S.insert(i);
            dfs(i, 1);

        }
        cout << res << endl;
    }
}
