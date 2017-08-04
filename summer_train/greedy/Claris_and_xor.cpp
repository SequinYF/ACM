/********************************************************************
 * File Name: Claris_and_xor.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 三  8/ 2 00:28:19 2017
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

#define N 60

int t;
ll a, b, c, d;

int main()
{
    cin >> t;
    W(t--){

        cin >> a >> b >> c >> d;
        ll xx = 0;
        ll yy = 0;
        int i;
        DOWN(i, N, 0){
            ll temp = 1;
            temp = temp << i;
            if(temp + xx <= b && temp + yy <= d){
                if(temp + xx < a && temp + yy < c){
                    xx += temp;
                    yy += temp;
                }
                else if(temp + xx < a)
                    xx += temp;
                else if(temp + yy < c)
                    yy += temp;
                else
                    xx += temp;
            }
            else if(temp + xx <= b)
                xx += temp;
            else if(temp + yy <= d)
                yy += temp;
        }
        ll ret = xx ^ yy;
        cout << ret << endl;
    }
}



