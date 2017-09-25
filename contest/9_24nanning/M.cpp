/********************************************************************
* File Name: M.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 一  9/25 16:34:54 2017
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
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define lowbit(x) (x&-x)
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}
#define maxn 10005
stringstream ss;
int N;
double k;
string buf;
ll num[55];
ll t;

int main() {

    ios_base::sync_with_stdio(false);
    MEM(num, 0);

    getline(cin, buf);
    ss << buf;
    ss >> N >> k;
    int m = 0;
    while(getline(cin, buf)) {
        
        ss.clear();
        ss << buf;

        while(ss >> t) {
            num[m] |= (1 << (t - 1));
        }
        m++;
    }
    
    int x = ceil(m * 1.0 * k);
    ll MAX = (1 << N);
    
   
    int sum = 0;
    for(ll i = 1; i <= MAX; i++) {
        int ret = 0;
        for(int j = 0; j < m; j++) {
            if((num[j] & i) == i) {
                ret++;
            }
        }

        if(ret >= x){
            sum++;
        }
    }

    cout << sum << endl;
    return 0;
}

