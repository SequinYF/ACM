/********************************************************************
* File Name: b2.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 日  8/13 15:26:14 2017
*************************************************************************/

#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
int city[10005];
int 
int ret;
int find_(int x){
    int t = x;

    while(pre[t] != t){
        t = pre[t];
    }

    int k = x;
    int m;
    while(k != t){
        m = pre[k];
        pre[k] = t;
        k = m;
    }

    return k;
}

bool join_(int x, int y){

    int xx = find_(x);
    int yy = find_(y);
    if(xx != yy){
        pre[yy] = xx; 
        return false;
    }

    return true;
}


struct node{
	int b;
	int v;
}

int main(){
    ios::sync_with_stdio(false);

//  freopen("D.txt", "r", stdin);

    int n ,m, T;
    cin >> T;
    while(T--) {
    	cin >> n >> m;
    	node v[100001];
    	memset(v, 0, sizeof(v));
    	pre[n] = n;
    	for(int i = 1; i <= n-1; i++) {
    		cin >> v[i].b >> v[i].v;
    		pre[i] = i;
     	}

     	for(int i = 1; i <= m; i++) {
     		int q;
     		cin >> q;
     		for(int j = 1; j <= q; j++) {
     			cin >> a[i][j];
     		}

     		for(int j = 1; j < q; j++) {
     			join(a[i][j], a[i][j+1]);
     		}
     	}


     	int Q;
     	cin >> Q;
     	for (int i = 0; i < Q; ++i)
     	{
     		int a, b;
     		cin >> a >> b;

     		int r1 = find_(a);
     		int r2 = find_(b);
     		if(r1 == r2) {
     			cout << 0 << endl;
     		}
     		else{
     			cout << v[r1].v << endl;
     		}
     	}

    }
}

#include <bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1e5+5;
int t,m,n,out;
typedef struct edge
{
    int to,val;
} edge;
vector<edge> E[maxn];
int f[maxn],a[maxn][32],deep[maxn],dis[maxn];
vector<int> O[maxn];
void dfs(int now)
{
    a[now][0]=f[now];
    for(int i=1; i<=31; i++)
        a[now][i]=a[a[now][i-1]][i-1];
    int lens=E[now].size();
    for(int i=0; i<lens; i++)
    {
        edge next=E[now][i];
        if(next.to!=f[now])
        {
            f[next.to]=now;
            deep[next.to]=deep[now]+1;
            dis[next.to]=dis[now]+next.val;
            dfs(next.to);
        }
    }
}
int lcaf(int x,int y)
{
    if(deep[x]<deep[y])
        swap(x,y);
    for(int i=31; i>=0; i--)
    {
        if(deep[y]<=deep[a[x][i]])
            x=a[x][i];
    }
    if(x==y)
        return x;
    for(int i=31; i>=0; i--)
    {
        if(a[x][i]!=a[y][i])
        {
            x=a[x][i];
            y=a[y][i];
        }
    }
    return a[x][0];
}
void init()
{
    f[1]=1;
    memset(f,0,sizeof(f));
    memset(a,0,sizeof(a));

    for(int i=1; i<=n; i++)
        E[i].clear(),O[i].clear();
}
int main()
{
    ios::sync_with_stdio(false);
    cin >> t;
    edge tmp;
    int Q,u,v,w,cot;
    while(t--)
    {
        cin >> n >> m;
        init();
        for(int i=1; i<n; i++)
        {
            cin >> u >> v >> w;
            tmp.to=v,tmp.val=w;
            E[u].push_back(tmp);
            tmp.to=u;
            E[v].push_back(tmp);
        }
        for(int i=1; i<=m; i++)
        {
            cin >> cot;
            for(int j=0; j<cot; j++)
            {
                cin >> u;
                O[i].push_back(u);
            }
        }
        dfs(1);
        cin >> Q;
        for(int i=0; i<Q; i++)
        {
            out=INF;
            cin >> u >> v;
            for(int j=0; j<O[u].size(); j++)
                for(int x=0; x<O[v].size(); x++)
                    out=min(out,dis[O[u][j]]+dis[O[v][x]]-dis[lcaf(O[u][j],O[v][x])]*2);
            cout << out << endl;
        }
    }
    return 0;
}