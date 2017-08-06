/********************************************************************
 * File Name: 3.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 日  8/ 6 14:38:30 2017
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
int a[100010];
int b[100010];
int k[10010];
int p[1010];
ll dp[1010][15];
int main(){
    int n,m;
    while(scanf("%d%d", &n, &m) != EOF){
        memset(dp, INF, sizeof(dp));

        int max1 = 0, max2 = 0;

        for(int i = 1; i <= n; i++){
            scanf("%d%d", &a[i], &b[i]);
            max1 = max(max1, b[i]);
        }
        for(int i = 1; i <= m;i++){
            scanf("%d%d", &k[i], &p[i]);
            max2 = max(max2, p[i]);
        }
        if(max2 <= max1){
            printf("-1\n");
            continue;
        }

        for(int i = 0;i <= 10; i++)
            dp[0][i] = 0;

        for(int i = 0; i <= 10; i++)
            for(int j = 1; j <= m; j++){
                int t = p[j] - i;
                if(t > 0){
                    for(int s = 1; s <= 1000; s++){
                        dp[s][i] = min(dp[s][i], dp[s-t][i] + k[j]);
                    }
                }
            }
        ll sum=0;

        for(int i = 1; i <= n; i++)
           sum += dp[a[i]][b[i]];
        printf("%I64d\n",sum);
    }
    return 0;
}
