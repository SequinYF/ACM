/********************************************************************
 * File Name: Sum_it_up.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 五  8/ 4 10:52:32 2017
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
int coun = 0;
int a[20];

int n, t;
int p, path[15];
int pp, ppath[15];
int r;
int ret[100006][50];

bool cmp(const int &a, const int &b){
    return a > b;
}

void dfs(int sum, int index){


    if(sum == t){
        int i, j;
        bool flag = false;
        UP(i, 0, p-1){
            if(path[i] != ppath[i]){
                flag = true;
            }
        }
        if(!flag){
            return;
        }
        memcpy(ppath, path, sizeof(path));
        UP(i, 0, p-1){
            cout << path[i];
            if(i != p-1){
                cout << "+";
            }
        }
        cout << endl;
       // memcpy(ret[r]+1, path, sizeof(path));
        ret[r][0] = p;
        //cout << ret[r][0] << endl;
        r++;
        coun++;
        //cout << a[index] << "d" << coun <<endl;
        return;
    }
    if(index >= n){
        return;
    }
    int i;
    UP(i, index, n-1){
            sum += a[i];
            path[p++] = a[i];
            dfs(sum, i+1);
            p--;
            sum -= a[i];
            while(i < n-1 && a[i] == a[i+1])
                i++;
     
    }

}




int main(){
    while(cin >> t >> n && n + t){

        MEM(path, 0);
        int i, j;
        UP(i, 0, n-1){
            cin >> a[i];
        }

        sort(a, a+n, cmp);

        coun = 0;
        r = 0;
        printf("Sums of %d:\n", t);
        dfs(0, 0);   
        if(!coun){
            // UP(i, 0, r-1){
            //     int s = ret[i][0];
            //     //cout << s << endl;
            //     UP(j, 1, s){
            //         cout << ret[i][j];
            //         if(j != s){
            //             cout << "+";
            //         }    
            //     }
            //      cout << endl;
            // }
            cout << "NONE" << endl;
        }
        // else{
        //     cout << "NONE" << endl;
        // }
    }
}
