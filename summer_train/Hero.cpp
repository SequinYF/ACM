/********************************************************************
* File Name: Hero.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 二  8/ 1 17:45:15 2017
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
    int hp;
    int dps;
}info[21];


bool cmp(const NODE a, const NODE b){
    double aa = a.dps*1.0/a.hp*1.0;
    double bb = b.dps*1.0/b.hp*1.0;
    if(aa == bb){
        return a.hp < b.hp;
    }
    else{
        return aa > bb;
    }
}

int main(){
    int n;
    while(cin >> n){
        int i;
        int sum = 0;
        UP(i, 0, n-1){
            cin >> info[i].dps >> info[i].hp;
            sum += info[i].dps;
        }

        sort(info, info+n, cmp);

        int ret = 0;
        UP(i, 0, n-1){
            int t = info[i].hp;
            ret += (sum * t);
            sum -= info[i].dps;
        }

        cout << ret << endl;
    }
}
