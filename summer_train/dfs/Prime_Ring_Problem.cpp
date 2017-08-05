/********************************************************************
 * File Name: Prime_Ring_Problem.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 五  8/ 4 23:13:46 2017
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
#define MAX 1000005
#define MOD 1000000007
#define INF 0x3F3F3F3F
#define EXP 1e-8
#define lowbit(x) (x&-x)
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}
int ret[1][5000];
bool vis[50];
int rret[5000];
int R, r;

int prime(int a, int b)
{	int n = a + b;
    if(n == 2){
        return 1;
    }
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0) return 0;
    }
    return 1;

}

void dfs(int index, int pre, int border, int depth){

    if(depth > border){
        return;
    }

    if(depth == border){
        if(prime(index, 1)){
            memcpy(rret, ret[R], sizeof(ret[R]));
            for(int j = 0; j < border; j++){
                printf("%d ", rret[j]);
            }
            puts("");
        }
        return;
    }

    vis[index] = 0;
    pre = index;

    int i = 2;
    while(i <= border){
        if (vis[i] && prime(pre, i))
        {
            vis[i] = 0;
            ret[R][r++] = i;
            dfs(i, pre, border, depth+1);
            --r;
            vis[i] = 1;
        }
        i++;
    }
    return;
}

int main(){
    ios::sync_with_stdio(false);
    int t;
    int ii = 1;
    while(scanf("%d", &t)){
        memset(vis, 1, sizeof(vis));
        vis[1] = 0;
        r = 1;
        R = 0;
        ret[0][0] = 1;
        printf("Case %d:\n", ii);
        dfs(1, 1, t, 1);
        for(int i = 0; i < R; i++){
            puts("");
        }
        ii++;
    }
}

