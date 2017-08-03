/********************************************************************
* File Name: Points_in_Segments.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 三  8/ 2 14:13:53 2017
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
#define UP(i,x,y) for(int i=x;i<=y;i++)
#define DOWN(i,x,y) for(int i=x;i>=y;i--)
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

ll point[100005];
ll ret[100005];
int main(){
    int t;
    scanf("%d", &t);
    UP(ii, 1, t){
        int n, q;
        scanf("%d%d", &n, &q);
        UP(i, 0, n-1){
            scanf("%lld", &point[i]);
        }

        UP(i, 1, q){
            ll x, y;
            scanf("%lld%lld", &x, &y);

            ll l = lower_bound(point, point+n, x) - point;
            ll r = upper_bound(point, point+n, y) - point;

            //cout << "dew" << l << r << endl;

            ret[i] = r - l;
        }

        printf("Case %d:\n", ii);
        UP(i, 1, q)
            printf("%lld\n", ret[i]);
    }
}
