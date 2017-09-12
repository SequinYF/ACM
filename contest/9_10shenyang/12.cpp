/********************************************************************
* File Name: 12.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 二  9/12 21:14:27 2017
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

struct node {
    int num, val;
};
queue<node> Q;
int nn[100007];
int main() {
    int n;
    while(scanf("%d", &n)) {

        if(!Q.empty()) {
            Q.pop();
        }
        int all = 0;
        for(int i = 0; i < n; i++) {
            scanf("%d", &nn[i]);
            all += nn[i];
        }
        for(int i = 0; i < n; i++) {
            int x;
            scanf("%d", &x);
            node m;
            m.num = nn[i];
            m.val = nn[i] - x;
            Q.push(m);
        }
        int sum = 0;
        int ret = 0;
        int coun = 0;
        int change = 0;
        while(coun <= all) {
            node temp = Q.front();
            while(coun <= all) {
                change++;
                Q.pop();
                Q.push(temp);
                if(sum + temp.val < 0){
                    break;
                }
                sum += temp.val;
                coun += temp.num;
                temp = Q.front();
            }
            if(coun < all) {
                coun = 0;
                sum = 0;
                ret += change;
                change = 0;
            }
            else{
                break;
            }

        }

        printf("%d\n", ret);
    }

}
