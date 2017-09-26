/********************************************************************
 * File Name: hdu1166.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 二  9/26 19:47:25 2017
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

#define maxn 50005

int segTree[maxn << 2];
int arr[maxn];
int ret[maxn];

void build(int node, int s, int e) {
    if(s == e) {
        segTree[node] = arr[s];
    }
    else{
        build(node * 2 , s, ((s + e) >> 1));
        build(node * 2 + 1, ((s + e) >> 1) + 1, e);
        segTree[node] = segTree[node * 2] + segTree[node * 2 + 1];
        // cout << segTree[node] << endl;
    }
}

int query(int a, int b, int l, int r, int node) {
    if(l >= a && r <= b) {
        return segTree[node];
    }
    int ret = 0;
    int mid = (l + r) >> 1;

    if(a <= mid){
        ret += query(a, b, LS);
    }
    if(b > mid) {
        ret += query(a, b, RS);
    }
    return ret;
}

void update(int inde, int add, int l, int r, int node) {
    if(l == r) {
        segTree[node] += add;
        return;
    }
    int mid = (l + r) >> 1;
    if(inde <= mid) {
        update(inde, add, LS);
    }
    else{
        update(inde, add, RS);
    }
    segTree[node] = segTree[lson] + segTree[rson];
}

int main() {
    ios_base::sync_with_stdio(false);

    int T, t;
    cin >> T;
    UP(t, 1, T) {

        MEM(segTree, 0);
        MEM(arr, 0);
        MEM(ret, 0);

        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> arr[i];
        }
        build(1, 1, n);
        string s;
        int index = 0;
        while( cin >> s && s[0] != 'E'){
            int a, b;
            cin >> a >> b;
            if(s[0] == 'Q') {
                ret[index] = query(a, b, 1, n, 1);
                index++;
            }
            else if(s[0] == 'A') {
                update(a, b, 1, n, 1);
            }
            else if(s[0] == 'S') {
                update(a, -b, 1, n, 1);
            }
        }
        cout << "Case " << t << ":" << endl;

        for(int i = 0; i < index; i++) {
            cout << ret[i] << endl;
        }
    }
}
