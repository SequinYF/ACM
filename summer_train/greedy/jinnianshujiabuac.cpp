/********************************************************************
 * File Name: jinnianshujiabuac.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 二  8/ 1 17:19:17 2017
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

struct NODE{
    int s;
    int e;
}T[105];


int cmp(const NODE &a, const NODE &b) {
    if(a.s == b.s) {
        return a.e < b.e;
    } else {
        return a.s < b.s;
    }
}


int main(){
    int k;
    while(cin >> k && k){
        int i;
        UP(i, 0, k-1){
            cin >> T[i].s >> T[i].e;
        }

        sort(T, T+k, cmp);
        int temp, sum = 1;
        temp = T[0].e;
        UP(i, 1, k-1){
            if(temp <= T[i].s) {
                sum++;
                temp = T[i].e;
            } else if(T[i].e < temp) {
                temp = T[i].e;
            }
        }
        cout << sum << endl;
    }
    return 0;
}
