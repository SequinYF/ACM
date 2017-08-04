/********************************************************************
 * File Name: The_E-pang_Palace.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 二  8/ 1 16:21:58 2017
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
struct{
    int x, y;
}POS[31];

bool vis[201][201];

int judge(int a,int b,int c,int d)
{
    int res = 0;

    int lx1,lx2,ly1,ly2,rx1,rx2,ry1,ry2;
    lx1=min(POS[a].x,POS[b].x);
    ly1=min(POS[a].y,POS[b].y);
    lx2=min(POS[c].x,POS[d].x);
    ly2=min(POS[c].y,POS[d].y);
    rx1=max(POS[a].x,POS[b].x);
    ry1=max(POS[a].y,POS[b].y);
    rx2=max(POS[c].x,POS[d].x);
    ry2=max(POS[c].y,POS[d].y);

    if(lx1==lx2&&ly1==ly2&&rx1==rx2&&ry1==ry2)
        return res;

    if((ry1<ly2)||(ry2<ly1)||(lx1>rx2)||(lx2>rx1))
    {
        res=(rx1-lx1)*(ry1-ly1)+(rx2-lx2)*(ry2-ly2);
        return res;
    }

    if(lx2<lx1&&ly2<ly1&&rx1<rx2&&ry1<ry2)
    {
        res=(rx2-lx2)*(ry2-ly2);
        return res;
    }

    if(lx1<lx2&&ly1<ly2&&rx2<rx1&&ry2<ry1)
    {
        res=(rx1-lx1)*(ry1-ly1);
        return res;
    }

    else
        return 0;
}


int main(){
    int N;
    while(cin >> N && N){
        int area = 0;
        int i;
        if(N < 8){
            cout << "imp" << endl;
            continue;
        }

        MEM(vis, 0);

        UP(i, 0, N-1){
            cin >> POS[i].x >> POS[i].y;
            vis[POS[i].x][POS[i].y] = true;
        }

        int a, b;
        UP(a, 0, N-2){
            UP(b, a+1, N-1){
                int x1 = POS[a].x;
                int y1 = POS[a].y;
                int x2 = POS[b].x;
                int y2 = POS[b].y;

                if(x1 == x2 || y1 == y2){
                    continue;
                }

                if(vis[x1][y2] && vis[x2][y1]){
                    int m, n;
                    UP(m, 0, N-1){
                        if(m == a || m == b)
                            continue;
                        UP(n, m+1, N-2){
                            if(n == a || n == b)
                                continue;

                            int x1 = POS[m].x;
                            int y1 = POS[m].y;
                            int x2 = POS[n].x;
                            int y2 = POS[n].y;

                            if(x1 == x2 || y1 == y2){
                                continue;
                            }

                            if(vis[x1][y2] && vis[x2][y1]){

                                int sum = judge(a, b, m, n);
                                /*int aa = abs(POS[a].x - POS[b].x);
                                  int bb = abs(POS[a].y - POS[b].y);
                                  int sum = aa * bb;
                                  aa = abs(POS[m].x - POS[n].x);
                                  bb = abs(POS[m].y - POS[n].y);
                                  sum += aa * bb;
                                  */

                                //cout << area << endl;
                                area = max(area, sum);

                            }
                        }
                    }

                }
            }
            //for
        }
        if(area){
            cout << area << endl;
        }
        else{
            cout << "imp" << endl;
        }

    }
}
