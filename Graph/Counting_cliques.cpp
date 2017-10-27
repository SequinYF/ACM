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
#define ll long long
#define MAX 105

ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}
int n, m ,s;
int res;
bool mmap[MAX][MAX];
vector<int> G[MAX];
//set<int> S;
//set<int>::iterator iter;
bool vis[MAX];

//bool check(int v) {
//    for(iter = S.begin(); iter != S.end(); iter++) {
//        if(!mmap[*iter][v]){
//            return false;
//        }
//    }
//    return true;
//}


void dfs(int a[],int u, int now) {
    if(now >= s) {
        res++;
        return;
    }

    for(int i = 0; i < G[u].size(); i++) {
        int v = G[u][i];
        if(!vis[v]&&a[now]<v) 
		{
			int flag=1;
			for(int i=1;i<=now;i++)
			{
				if(mmap[a[i]][v]!=1)
				{
					flag=0;
					break;
				}
			}
			if(flag)
			{
				a[now+1]=v;
            	vis[v] = 1;
            	dfs(a, v, now+1);
            	vis[v] = 0;
            }
        }
    }
}


int main() {
    int T;
    //ios::sync_with_stdio(false);
    //cin >> T;
    scanf("%d",&T);
    while(T--) {
        //cin >> n >> m >> s;
        scanf("%d%d%d",&n,&m,&s);
        //MEM(mmap, 0);
        memset(mmap,0,sizeof(mmap));
		for(int i = 1; i <= n; i++) {
            vis[i] = 0;
            G[i].clear();
        }
        res = 0;
       
        for(int i = 0; i < m; i++) {
            int a, b;
            //cin >> a >> b;
            scanf("%d%d",&a,&b);
            mmap[a][b] = 1;
            mmap[b][a] = 1;
            G[a].push_back(b);

        }
        int shu[105];
        for(int i = 1; i <= n; i++){
            shu[1]=i;
            dfs(shu,i,1);
        }
        //cout << res << endl;
        printf("%d\n",res);
    }
}