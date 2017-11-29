/********************************************************************
 * File Name: hdu1754.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 二  9/26 21:18:47 2017
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

#define lson 2*node
#define rson 2*node+1
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

#define maxn 200005
int segTree[maxn << 2];


void build(int l, int r, int node) {
    if(l == r) {
        cin >> segTree[node];
    }
    else{
        int mid = (l + r) >> 1;
        build(LS);
        build(RS);
        segTree[node] = max(segTree[lson], segTree[rson]);
    }
}


int query(int a, int b, int l, int r, int node) {
    if(l >= a && r <= b) {
        return segTree[node];
    }

    int ret = 0;
    int mid = (l + r) >> 1;
    if(a <= mid) {
        ret = max(query(a, b, LS), ret);
    }
    if(b > mid) {
        ret = max(query(a, b, RS), ret);
    }

    return ret;
}

void update(int index, int add, int l, int r, int node) {
    if(l == r) {
        segTree[node] = add;
        return;
    }

    int mid = (l + r) >> 1;
    if(index <= mid) {
        update(index, add, LS);
    }
    else{
        update(index, add, RS);
    }

    segTree[node] = max(segTree[lson], segTree[rson]);
}


int main() {
    ios_base::sync_with_stdio(false);
    int n, m;
    while(cin >> n >> m) {
        MEM(segTree, 0);
        build(1, n, 1);
        char ch;
        while(m--) {
            cin >> ch;
            int a, b;
            cin >> a >> b;

            if(ch == 'Q') {
                int ret = query(a, b, 1, n, 1);
                cout << ret << endl;
            }
            else if(ch == 'U') {
                update(a, b, 1, n, 1);
            }
        }
    }
}
