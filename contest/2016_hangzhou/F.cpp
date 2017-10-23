/********************************************************************
 * File Name: F.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 一 10/23 18:18:18 2017
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
#define MAX 10000005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define lowbit(x) (x&-x)
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}

ll num[1003];

ll make(ll x, ll y) {
    int ret = 0;
    while(x < y) {
        ret = ret * 10 + num[x++];
    }
    return ret;
}


int main() {
    ios::sync_with_stdio(false);
    ll T, t;
    cin >> T;
    UP(t, 1, T) {
        memset(num, 0, sizeof(num));
        ll ans = 0;
        string str;
        cin >> str;
        for(ll i = 1; i <= str.length(); i++) {
            num[i] = str[i-1] - '0';
        }
        for(ll i = 3; i + 2<= str.length(); i++) {
            ll ab = 0;
            ab = max(ab, make(1, i-1) + num[i-1]);
            ab = max(ab, num[1] + make(2, i));
            ll e = 0;
            for(ll j = i+2; j <= str.length(); j++) {
                e = max(e, make(j, str.length()+1));
            }
            //cout << ab << " " << e << endl;

            ans = max(ans, ab - num[i] * num[i+1] / e);
        }
        cout << "Case #" << t << ": " << ans << endl;
    }
    return 0;
}
