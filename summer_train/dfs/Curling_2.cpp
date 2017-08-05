/********************************************************************
 * File Name: Curling_2.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 五  8/ 4 15:21:30 2017
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

struct node{
    int x, y;
};
int dis[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};//右左上下
int vis[25][25];
node s, g;
int w, h;
int ret;
//bool flag;
void dfs(int xx, int yy, int step, int dir){
    if(step > 10){
        return;
    }

    int x = xx, y = yy;
    int cnt = 0;
    W(vis[x][y] == 1){
        x += dis[dir][0];
        y += dis[dir][1];
        cnt++;
      //  cout << "vis" << vis[x][y] << endl;
    }
    if(x > h || x < 1 || y > w || y < 1){
        return;
    }
    else if(x == g.x && y == g.y){
       // printf("des: %d %d, point: %d %d, dir: %d\n", g.x, g.y, xx, yy, dir);
        //flag = true;
        ret = min(ret, step);
      //  cout << xx << yy << endl;
        return;
    }
    else{
        if(cnt == 1){
            return;
        }
        int i, j;
        UP(i, 0, 3)
        {
            vis[x][y] = 1;
            dfs(x-dis[dir][0], y-dis[dir][1], step+1, i);
            vis[x][y] = 0;
        }
        return;
    }
}



int main(){
    while(cin >> w >> h && w + h){
        MEM(vis, 0);
        int i, j;
        ret = INF;
        s.x = s.y = g.x = g.y = -1;
       // flag = false;
        UP(i, 1, h){
            UP(j, 1, w){
                int t;
                cin >> t;
                switch(t){
                    case 0:
                        vis[i][j] = 1;
                        break;
                    case 1:
                        vis[i][j] = 0;
                        break;
                    case 2:s.x = i;
                           s.y = j;
                           vis[i][j] = 1;
                           break;
                    case 3:g.x = i;
                           g.y = j;
                           vis[i][j] = 0;
                           break;
                }
            }
        }
        //   UP(i, 1, w){
        //     UP(j, 1, h){
        //         cout << vis[i][j];
        //     }
        //     cout << endl;
        // }
        if(s.x<0 || s.y<0 || g.x<0 || g.y < 0)
        {
            cout << -1 << endl;
            continue;
        }
        UP(i, 0, 3){
            dfs(s.x, s.y, 1, i);
        }
        if(ret <= 10){
       // if(flag && ret <= 10){
            cout <<ret << endl;
        }
        else{
            cout << -1 << endl;
        }
    }
}
