/********************************************************************
 * File Name: 9.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 日  9/17 12:43:35 2017
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


#define MAXN 205


int max_flow(int n, int mat[][MAXN], int source, int sink) {
    int v[MAXN], c[MAXN], p[MAXN], ret = 0, i, j;
    for (;;)
    {
        for (i = 0; i < n; i++) {
            v[i] = c[i] = 0;
        }
        for (c[source] = INF; ;) {
            for (j = -1, i = 0; i < n; i++) {
                if (!v[i] && c[i] && (j == -1 || c[i] > c[j])) {
                    j = i;
                }

            }
            if (j < 0) {
                return ret;
            }
            if (j == sink) {
                break;
            }
            for (v[j] = 1, i = 0; i < n; i++){
                if (mat[j][i] > c[i] && c[j] > c[i]) {
                    c[i] = mat[j][i] < c[j] ? mat[j][i] : c[j], p[i] = j;
                }

            }
        }
        for (ret += j = c[i = sink]; i != source; i = p[i]) {
            mat[p[i]][i] -= j, mat[i][p[i]] += j;
        }

    }
}


int min_edge_cut(int n, int mat[][MAXN], int source, int sink, int set[][2]) {
    int m0[MAXN][MAXN], m[MAXN][MAXN], i, j, k, l, ret = 0, last;
    if (source == sink)
    {
        return -1;
    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m0[i][j] = (mat[i][j] != 0);
        }

    }
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++) {
            m[i][j] = m0[i][j];
        }

    }
    last = max_flow(n, m, source, sink);
    for (k = 0; k < n && last; k++)
    {
        for (l = 0; l < n && last; l++) {
            if (m0[k][l]) {
                for (i = 0; i < n + n; i++) {
                    for (j = 0; j < n + n; j++) {
                        m[i][j] = m0[i][j];
                    }

                }
                m[k][l] = 0;
                if (max_flow(n, m, source, sink) < last) {
                    set[ret][0] = k; set[ret++][1] = l; m0[k][l] = 0;last--;
                }
            }
        }

    }
    return ret;
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int mat[MAXN][MAXN];
        int se[MAXN][2];
        int n, m;
        scanf("%d%d", &n, &m);
        int s, t;
        scanf("%d%d", &s, &t);
        MEM(mat, 0);
        MEM(se, 0);
        for(int i = 0; i < m; i++) {
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            mat[a-1][b-1] = c;
            //mat[b-1][a-1] = c;
        }

        int ret = min_edge_cut(n, mat, s-1, t-1, se);

        cout << ret << endl;
    }
}
