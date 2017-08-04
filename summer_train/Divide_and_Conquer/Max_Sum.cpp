/********************************************************************
 * File Name: Max_Sum.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 五  8/ 4 09:01:37 2017
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

int x, y;
int a[100007];
int sum=0;
struct node{
    int x, y;
    int v;
};
node mmax;

node merge_m(int l, int r, int mid, node lmax, node rmax){

    if(lmax.v > rmax.v){
        mmax = lmax;
    }
    else{
        mmax = rmax;
    }

    lmax.v = a[mid];
    rmax.v = a[mid+1];
    int i, temp = 0;
    DOWN(i, mid, l){
        temp += a[i];
        if(temp >= lmax.v){
            lmax.v = temp;
            lmax.x = i;
        }
    }

    temp = 0;
    UP(i, mid+1, r){
        temp += a[i];
        if(temp >= rmax.v){
            rmax.v = temp;
            rmax.y = i;
        }
    }
    if(mmax.v > lmax.v + rmax.v){
        return mmax;
    }
    else{
        mmax.x = lmax.x;
        mmax.y = rmax.y;
        mmax.v = lmax.v + rmax.v;
        return mmax;
    }

}


node merge(int l, int r){
    node tm;
    if(l == r){
        tm.v = a[l];
        tm.x = l;
        tm.y = l;
        return tm;
    }
    node ml, mr;
    int mid = (r + l)/2;
    ml = merge(l, mid);
    mr = merge(mid+1, r);
    node ret;
    ret = merge_m(l, r, mid, ml, mr);
    return ret;
}

int main(){
    int t, ii, j, i;
    cin >> t;
    UP(ii, 1, t){
        mmax.v = -INF;
        int n;
        cin >> n;
        UP(i, 1, n){
            cin >> a[i];
        }
        node ret;
        ret = merge(1, n);

        printf("Case %d:\n", ii);
        cout << ret.v << " "<<ret.x <<" "<< ret.y<<endl;
        if(ii < t){
            cout << endl;
        }
    }
    return 0;
}
