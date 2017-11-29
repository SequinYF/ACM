/********************************************************************
 * File Name: Fire.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 三  9/13 16:21:54 2017
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

int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};

struct node{
    int x, y;
    int step;
};

queue <node> q;

char ch[1001];
int coun[1001][1001];
bool vis[1001][1001];
bool visf[1001][1001];
int f[1001][2];
int ji, jj;
int n, m;
int cnt;

bool check(node a, int step) {
    if(a. x < 0 || a.y < 0 || a.x >= n || a.y >= m || vis[a.x][a.y] || visf[a.x][a.y]){
        //cout << "fds" << a.x << a.y << endl;
        return false;
    }
    if(coun[a.x][a.y] == step && coun[a.x][a.y]) {
        //cout << "fds" << a.x << a.y << endl;
        return false;
    }
        // cout << "true" << a.x <<  " "<< a.y << a.y << endl;
        return true;
}


void bfsf() {
    while(!q.empty()) {
        node no = q.front();
        q.pop();
        node tmp;
        for(int i = 0; i < 4; i++) {
            tmp.x = no.x + dir[i][0];
            tmp.y = no.y + dir[i][1];

            if(check(tmp, 0)){
                q.push(tmp);
                visf[tmp.x][tmp.y] = 1;
                coun[tmp.x][tmp.y] += cnt;
            }
        }
        cnt++;
    }
    MEM(visf, 0);
}

int bfs() {
    while(!q.empty()) {
        node no = q.front();
        q.pop();
        node tmp;
        for(int i = 0; i < 4; i++) {
            tmp.x = no.x + dir[i][0];
            tmp.y = no.y + dir[i][1];

            if(check(tmp, no.step + 1)){
                tmp.step = no.step + 1;
                if(tmp.x == n - 1 || tmp.y == m-1 || tmp.x == 0 || tmp.y == 0){
                    //            cout << tmp.x << " " << tmp.y  <<" " <<tmp.step<< endl;
                    return tmp.step;
                }
                vis[tmp.x][tmp.y] = 1;
                tmp.step = no.step + 1;
                //          cout << "dd" <<tmp.step << endl;
                q.push(tmp);
            }
        }
    }
    return -1;
}





int main() {

    int N;
    scanf("%d", &N);
    while(N--) {
        MEM(coun, 0);
        MEM(vis, 1);
        MEM(visf, 1);
        cnt = 1;
        scanf("%d%d", &n, &m);
        node t;
        for(int i = 0; i < n; i++) {
            scanf("%s", ch);
            for(int j = 0; j < m; j++) {
                char tmp = ch[j];
                if(tmp == '.') {
                    vis[i][j] = 0;
                    visf[i][j] = 0;
                }
                else if(tmp == 'F') {
                    t.x = i;
                    t.y = j;
                    q.push(t);
                    coun[i][j] += cnt;
                    visf[i][j] = 1;
                }
                else if(tmp == 'J') {
                    ji = i;
                    jj = j;
                    vis[ji][jj] = 0;
                }
            }
        }
        bfsf();

        int ret;
        t.x = ji;
        t.y = jj;
        t.step = 0;
        q.push(t);

        ret = bfs();

        if(ret > 0) {
            printf("%d\n", ret);
        }
        else{
            puts("IMPOSSIBLE");
        }
    }
    return 0;
}
