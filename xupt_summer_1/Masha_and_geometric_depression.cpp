#include <bits/stdc++.h>

using namespace std;
const int MAXN=1e5+7;

long long b1,q,l,m;
map<long long,bool>vis;
int main()
{
    scanf("%I64d%I64d%I64d%I64d",&b1,&q,&l,&m);
    long long x;
    for(int i=0; i<m; ++i)
    {
        scanf("%I64d",&x);
        vis[x]=1;
    }

    if(!b1)
    {
        if(!vis[0])puts("inf");
        else puts("0");
    }
    else if(!q)
    {
        if(abs(b1)>l)puts("0");
        else
        {
            if(!vis[0])puts("inf");
            else
            {
                if(!vis[b1])puts("1");
                else puts("0");
            }
        }
    }
    else if(abs(b1)<=l&&abs(q)==1)
    {
        if(q==1)
        {
            if(!vis[b1])puts("inf");
            else puts("0");
        }
        else
        {
            if(vis[b1]&&vis[-b1])puts("0");
            else puts("inf");
        }
    }
    else
    {
        long long sum=0;
        long long t=b1;
        while(abs(t)<=l)
        {
            if(!vis[t])sum++;
            t*=q;
        }
        printf("%I64d\n",sum);
    }

    return 0;
}
