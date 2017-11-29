/*******************************************************************
* File Name: d.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 三 11/ 1 15:40:07 2017
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

struct node{
    int x, y;
}node[101];

vector <int> ve[101];
vector <int> :: iterator iter;

bool dis(int x, int y, int a, int b, int r) {
    int xx = (x - a) * (x - a);
    int yy = (y - b) * (y - b);
    int d = xx + yy;
    if((r * r) >= d) {
        return true;
    }

    return false;
}

int safe[101];
int main() {
    int T;
    cin >> T;
    while(T--)  {
        int n, R, r;
        cin >> n >> R >> r;
        for(int i = 1; i <= n; i++) {
            cin >> node[i].x >> node[i].y;
            ve[i].clear();
            safe[i] = 0;
        }

        int ans = 1;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                    bool ret = dis(node[i].x, node[i].y, node[j].x, node[j].y, r);
                    if(ret) {
                        safe[j]++;
                    }
            }
        }

        for(int i = 1; i <= n; i++) {
            ans = max(ans, safe[i]);
        }

        int aa = 0;
        for(int i = 1; i <= n; i++) {
            if(safe[i] == ans) {
                aa++;
            }
        }
        cout << aa << endl;
        for(int i = 1; i <= n; i++) {
            if(safe[i] == ans) {
                cout << i << endl;
            }
        }

    }
}
