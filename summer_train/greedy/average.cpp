/********************************************************************
 * File Name: average.cpp
 * Author: Sequin
 * mail: Catherine199787@outloflag.com
 * Created Time: 三  8/ 2 00:50:57 2017
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

ll a[100015];
struct{
    int x, y;
}path[100005];


int m = 0;

int n;
bool fun()
{
    ll i;
    a[n+1] = a[1];
    UP(i, 1, n)
    {
        if(abs(a[i]) > 1)
            return false;
        if(a[i] == -1)
        {
            path[m].x = i+1;
            if(path[m].x > n){
                path[m].x = 1;
            }
            path[m].y = i;
            m++;
            a[i]++;
            a[i+1]--;

        }
        if(a[i] == 1)
        {
            path[m].x = i+1;
            if(path[m].x > n){
                path[m].x = 1;
            }
            path[m].y = i;
            m++;
            a[i]--;
            a[i+1]++;
        }
    }
    return true;
}
int main()
{
    std::ios::sync_with_stdio(false);

    int T;
  //  cin >> T;
    scanf("%d", &T);
    W(T--)
    {
        ll i;
        ll sum = 0;
        m = 0;
        scanf("%d", &n);
        UP(i, 1, n){
            //cin >> a[i];
            scanf("%lld", &a[i]);
            sum += a[i];
        }

        if(sum % n)
            puts("NO");
            //cout << "NO" << endl;
        else if(sum < n){
            puts("NO");
            //cout << "NO" << endl;
        }
        else
        {
            ll ave = sum / n;
            UP(i, 1, n)
                a[i] -= ave;
            if(!fun())
            {
                puts("NO");
                //cout << "NO" << endl;
            }
            else
            {
                puts("YES");
                //cout << "YES" << endl;
                printf("%d\n", m);
                //cout << m << endl;
                UP(i, 0, m-1){
                    printf("%d %d\n", path[i].x, path[i].y);
                    //cout << path[i].x << path[i].y << endl;
                }
            }
        }
    }
}



