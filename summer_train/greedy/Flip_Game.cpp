/********************************************************************
 * File Name: Flip_Game.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 二  8/ 1 21:40:13 2017
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
#define N 4

int step;
int ret = 0;
bool chess[10][10];
bool copy_[10][10];

void flip(int i, int j){
    ret++;
    copy_[i][j] ^= 1;
    copy_[i-1][j] ^= 1;
    copy_[i+1][j] ^= 1;
    copy_[i][j-1] ^= 1;
    copy_[i][j+1] ^= 1;
}

bool fun(int way){
    int i, j;
    ret = 0;
    memcpy(copy_, chess, sizeof(chess));

    UP(i, 1, N){
        if(way & (1 << (N-i))){
            flip(1, i);
        }
    }
       UP(i, 2, N){
        UP(j, 1, N){
            if(copy_[i-1][j] == true){
                flip(i, j);
            }
        }
    }
/* UP(i, 1, N){
        UP(j, 1, N){
            cout << copy_[i][j];
        }
        cout << endl;
    }
    */

    UP(i, 1, N){
        if(copy_[N][i] == 1){
          //  cout << copy_[N][i] << i << endl;
            return false;
        }
    }
    return true;
}

int main(){
    int i, j;
    step = 17;
    UP(i, 1, 4){
        UP(j, 1, 4){
            char t;
            scanf("%c", &t);
            if(t == 'b'){
                chess[i][j] = true;
            }
            else{
                chess[i][j] = false;
            }
        }
        getchar();
    }

    int u = 2;
    W(u--){
        UP(i, 0, ((1 << N)-1)){
            if(fun(i) && ret < step){
                step = ret;
            }
        }
        //cout << step << endl;
        UP(i, 1, N)
            UP(j, 1, N){
                chess[i][j] ^= 1;
            }
    }
    if(step > 16){
        cout << "Impossible" << endl;
    }
    else
        cout << step  << endl;
}
