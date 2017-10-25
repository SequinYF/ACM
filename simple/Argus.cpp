/********************************************************************
* File Name: Argus.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 三 10/25 11:15:16 2017
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
#define MAX 1005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define lowbit(x) (x&-x)
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}

struct node {
    ll num;
    ll period;
    ll time;

    bool operator < (const node &a) const {
        if(a.time == time) {
            return a.num < num;
        }

        return a.time < time;
    }
};

priority_queue<node> q;


int main() {
    string s;
    node t;

    while(cin >> s && s != "#") {
        cin >> t.num >> t.time;
        t.period = t.time;
        q.push(t);
    }

    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        node now;
        now = q.top();
        cout << now.num << endl;
        q.pop();
        now.time += now.period;
        q.push(now);
    }
    return 0;
}
