/********************************************************************
 * File Name: 7_26.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 三  7/26 08:27:23 2017
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
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define lowbit(x) (x&-x)
//ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}
int n, k;
int ret;
bool canset[10];
char mmap[10][10];

int dfs(int chess, int border){
    if(chess > k){
        ret++;
        return 0;
    }

    int i, j;
    UP(i, border, n){
        UP(j, 1, n){
            if(canset[j] && mmap[i][j] == '#'){
                canset[j] = false;
                dfs(chess+1, i+1);
                canset[j] = true;
            }
        }
    }
    return 0;
}


int main(){

    //ios::sync_with_stdio(false);

    while(~scanf("%d%d", &n, &k) && n != -1 && k != -1){
        MEM(canset, 1);
        MEM(mmap, 0);
        ret = 0;
        int i;
        UP(i, 1, n){
            scanf("%s", mmap[i] + 1);
        }
        dfs(1, 1);
        printf("%d\n", ret);
    }
}















