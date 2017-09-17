/********************************************************************
* File Name: 1.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 日  9/17 11:53:08 2017
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
#define MAX 10000005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define lowbit(x) (x&-x)
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}

map <string, int> mm;

int main() {
    mm["rat"] = 1;
    mm["ox"] = 2;
    mm["tiger"] = 3;
    mm["rabbit"] = 4;
    mm["dragon"] = 5;
    mm["snake"] = 6;
    mm["horse"] = 7;
    mm["sheep"] = 8;
    mm["monkey"] = 9;
    mm["rooster"] = 10;
    mm["dog"] = 11;
    mm["pig"] = 12;

    int T;
    scanf("%d", &T);
    while(T--) {
        string a1, a2;
        cin >> a1 >> a2;

        if(a1 == a2) {
            cout << 12 << endl;
        }
        else{
            if(mm[a1] > mm[a2]){
             cout <<  mm[a2] + 12 - mm[a1] << endl;
            }
            else{
            cout << mm[a2] - mm[a1] << endl;
            }
        }
    }


    return 0;
}
