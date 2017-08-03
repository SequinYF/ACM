/********************************************************************
 * File Name: drying.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 三  8/ 2 14:56:44 2017
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
ll clo[100005];

int main(){
    int n, i;
    ll k;
    scanf("%d", &n);
    UP(i, 0, n-1){
        scanf("%lld", &clo[i]);
    }
    scanf("%lld", &k);

    sort(clo, clo+n);
    if(k == 1){
        printf("%lld\n", clo[n-1]);
        return 0;
    }

    int l = 1, r = clo[n-1];
    ll mid = 0;
    while(r > l){
        mid = (l + r)/2;
        ll time = 0;
        UP(i, 0, n-1){
            if(clo[i] > mid){
                ll t = ceil((clo[i] - mid)*1.0/(k-1));
                time += t;
            }
        }

//            cout << time << endl;


        if(time > mid){
            l = mid + 1;
        }
        else if(time <= mid){
            r = mid;
        }
    }

    mid = (r+l)/2;

    printf("%lld\n", mid);
}
