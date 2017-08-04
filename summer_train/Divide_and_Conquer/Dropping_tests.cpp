/********************************************************************
 * File Name: Dropping_tests.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 四  8/ 3 11:06:03 2017
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

int main(){
    int n, k;
    while(scanf("%d%d", &n ,&k) && n + k){
        int a[n+2];
        int b[n+2];
        double d[n+2];
        int i, j;
        double r = 0;
        double l = 0;
        double mid = 0;
        UP(i, 1, n){
            scanf("%d", &a[i]);
            //cout << a[i] << endl;
        }
        UP(i, 1, n){
            scanf("%d", &b[i]);
           // cout << b[i] << endl;
        }
        UP(i, 1, n){
            double t = 1.0*a[i]/b[i];
            r = max(r, t);
        }
        while(r-l>1e-6){
            mid = (l + r)/2;
            //cout << mid << endl;
            UP(i, 1, n){
                d[i] = a[i] - mid * b[i];
                // cout << d[i] << "dsj" << mid <<  endl;
            }

            sort(d+1, d+n+1);
            double temp = 0;
            //UP(i, k+1, n)
            //{
                DOWN(j, n, k+1){
                temp += d[j];
                //}
                //sum = max(sum, temp);
            }

           // cout << temp << "d" << mid << endl;
            if(temp > 0){
                l = mid;
            }
            else{
                r = mid;
            }
        }
        printf("%.0f\n", mid*100);
    }

    return 0;
}
