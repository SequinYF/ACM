/********************************************************************
* File Name: b.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 一  7/31 23:19:40 2017
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
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define lowbit(x) (x&-x)
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}

int num[1000003];
int main(){
    ll k;
    string n;
    while(cin >> k >> n){
        int count = 0;
        int i;
        int len = n.length();
        ll sum = 0;
        UP(i, 0, len-1){
           sum += (n[i]-'0');
           num[i] = (n[i] - '0');
        }

        if(sum >= k){
            cout << 0 << endl;
        }
        else{
            ll ret = k - sum;
            sort(num, num+len-1);
            UP(i, 0, len-1){
                int t = 9-num[i];
                if(t == 0){
                    continue;
                }
                ret -= t;
                count++;
                if(ret <= 0){
                    break;
                }
            }

        cout << count << endl;
        }
    }
}
