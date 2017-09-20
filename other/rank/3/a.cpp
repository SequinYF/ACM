/********************************************************************
* File Name: a.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 三  9/20 16:35:06 2017
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
#define MAX 100005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define lowbit(x) (x&-x)
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}

bool vis[MAX];
bool hei[MAX];
ll whi, bla;

vector<int>edg[MAX];


void creat_(int in, bool flag){

    flag = 1 ^ flag;
    for(int i = 0; i < edg[in].size(); i++) {
        if(!vis[edg[in][i]]){
            if(flag){
                bla++;
            }
            else{
                whi++;
            }
            vis[edg[in][i]] = 1;
            hei[edg[in][i]] = flag;
            creat_(edg[in][i], flag);
        }
    }
}




int main(){
    int n;
    cin >> n;

    bla = 0;
    whi = 0;
    MEM(vis, 0);
    MEM(hei, 0);
    for(int i = 0; i < n-1; i++) {
        int a, b;
        cin >> a >> b;

        edg[a].push_back(b);
        edg[b].push_back(a);
    }

    vis[1] = 1;
    hei[1] = 1;
    bla = 1;
    creat_(1, 1);

    ll t = bla * whi;
    cout << abs(t - n + 1) << endl;
}
