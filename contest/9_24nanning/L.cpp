/********************************************************************
* File Name: L.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 一  9/25 17:22:11 2017
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

#define maxn 1000005
int a[maxn];
int f[maxn];
int d[maxn];

int bsearch(const int *f, int size, const int &a) {
    int l = 0;
    int r = size - 1;
    while(l <= r) {
        int mid = (l + r)/2;
        if(a >= f[mid - 1] && a < f[mid]){
            return mid;
        }
        else if(a < f[mid]) {
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    return -1;
}


int LIS(const int *a, const int &n) {
    int i, j, size = 1;
    f[0] = a[0];
    d[0] = 1;
    for(int i = 1; i < n; i++) {
        if(a[i] < f[0]) {
            j = 0;
        }
        else if(a[i] >= f[size - 1]) {
            j = size++;
        }
        else{
            j = bsearch(f, size, a[i]);
        }
        f[j] = a[i];
        d[i] = j + 1;
    }
    return size;
}



int main() {
    freopen("test.txt", "r", stdin);
    int num;
    int index = 0;
    while(cin >> num) {
        int val;
        if(num >= 10000) {
            val = 5;
            num -= 10000;
        }
        else if(num < 0) {
            val = 0;
        }
        else{
            val = 1;
        }

        while(val--) {
            a[index++] = num;
        }
  //      cout << num << endl;
    }

    cout << LIS(a, index) << endl;
}
