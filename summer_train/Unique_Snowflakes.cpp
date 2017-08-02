/********************************************************************
 * File Name: Unique_Snowflakes.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 二  8/ 1 14:13:29 2017
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
#define pii pair<ll,ll>
#define ll long long
#define MAX 1000005
#define MOD 1000000007
#define INF 0x3F3F3F3F
#define EXP 1e-8
#define lowbit(x) (x&-x)
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}
map <ll, ll> mmap;
ll a[10000009];

int main(){
    ll k;
    cin >> k;
    while(k--){
        ll n;
        cin >> n;
        ll i;
        UP(i, 0, n-1){
            ll t;
            cin >> t;
            a[i] = t;
            mmap[t] = 0;
        }
        ll j = 0;
        ll num = 0;
        ll ret = 0;
        UP(i, 0, n-1){
            if(mmap[a[i]] == 0){
                num++;
            }
            mmap[a[i]]++;
            while(mmap[a[i]] > 1){
                if(a[i] == a[j]){
                    j++;
                    mmap[a[i]]--;
                    break;
                }
                mmap[a[j]]--;
                num--;
                j++;
            }

            if(num > ret){
                ret = num;
            }
        }

        cout << ret << endl;
    }
}
