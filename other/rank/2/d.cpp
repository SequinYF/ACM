/********************************************************************
 * File Name: d.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 四  9/21 16:17:44 2017
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
#define MAX 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define lowbit(x) (x&-x)
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}

struct node{
    string name;
    int v;
    int se;

    friend bool operator < (node a, node b){
        if(a.v == b.v)
            return a.se > b.se;
        else
            return a.v < b.v;
    }
}fri[MAX];


struct nodet{
    int t, c;
}qu[MAX];

string ret[MAX];

bool cmp(nodet a, nodet b){
    return a.t < b.t;
}


int main(){
    std::ios::sync_with_stdio(false);
    int T;
    cin >> T;
    while(T--){

        priority_queue<node> Q;
        int q, m, k;
        cin >> q >> m >> k;
        
        for(int i = 1; i <= q; i++){
            cin >> fri[i].name >> fri[i].v;
            fri[i].se = i;
        }

        int now = 1;
        int sum = 1;
        
        for(int i = 0; i < m; i++){
            cin >> qu[i].t >> qu[i].c;
        }

        sort(qu, qu+m, cmp);

        for(int i = 0; i < m; i++) {
            int t, c;
            t = qu[i].t;
            c = qu[i].c;

            while(now <= t && now <= q) {
                Q.push(fri[now]);
                now++;
            }

            for(int j = 0; j < c && !Q.empty(); j++) {
                node temp = Q.top();
                ret[sum++] = temp.name;
                Q.pop();
            }
        }

        for(int i = now; i <= q; i++){
            Q.push(fri[i]);
        }
        while(!Q.empty()){
            node temp = Q.top();
            ret[sum++] = temp.name;
            Q.pop(); 
        }

        int num;
        for(int i = 0; i < k-1; i++) {
            cin >> num;
            cout << ret[num] << " ";
        }
        cin >> num;
        cout << ret[num] << endl;
    }
    return 0;
}
