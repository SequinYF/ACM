/********************************************************************
* File Name: hdu1394.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 三  9/27 11:29:02 2017
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

#define lson node << 1
#define rson node << 1 | 1
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

#define maxn 5005

int segTree[maxn << 2];
int num[maxn];

void build(int l, int r, int node) {
    if(l == r) {
        segTree[node] = 0;
    }
    else{
        int mid = (l + r) >> 1;
        build(LS);
        build(RS);
    }
}


int query(int a, int b, int l, int r, int node) {
    if(l >= a && r <= b) {
        return segTree[node];
    }

    int re = 0;
    int mid = (l + r) >> 1;
    if(a <= mid) {
        re += query(a, b, LS);
    }
    if(mid < b) {
        re += query(a, b, RS);
    }
    return re;
}

void update(int index, int l, int r, int node) {
    if(l == r) {
        segTree[node]++;
        return;
    }
    int mid = (l + r) >> 1;
    if(index <= mid) {
        update(index, LS);
    }
    else{
        update(index, RS);
    }
    segTree[node] = segTree[lson] + segTree[rson];
}


int main() {
    int n;
    ios_base::sync_with_stdio(false);
    while(cin >> n) {
        MEM(segTree, 0);
        build(0, n-1, 1);

        for(int i = 0; i < n; i++) {
            cin >> num[i];
        }
        int ret = 0;
        for(int i = 0; i < n; i++) {
            ret += query(num[i], n-1, 0, n-1, 1);
            update(num[i], 0, n-1, 1);
        }

        int ans = ret;
        for(int i = 0; i < n; i++) {
            ret = ret - num[i] + n - num[i] - 1;
            ans = min(ret, ans);
        }

        cout << ans << endl;
    }
    return 0;
}
