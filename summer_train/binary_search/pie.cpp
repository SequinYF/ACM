/********************************************************************
 * File Name: pie.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 三  8/ 2 17:38:43 2017
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


double rr[10005];

bool cmp(double a,double b){
    return a > b;
}

int main (){
    int n, f, t;
    double mmax;
    double sum;
    scanf("%d",&t);
    W(t--){
        scanf("%d%d", &n, &f);
        int i;
        UP(i, 0, n-1){
            int r;
            scanf("%d", &r);
            rr[i] = pi * r * r;
            mmax = max(mmax , rr[i]);
            sum += rr[i];
        }
        sort(rr, rr + n,cmp);
        f++;
        double l = mmax/f, mid;
        int count;
        double r = sum/f;
        W(true){
             if(r - l <= 1e-6) //////!!!!!!!
            {
                break;
            }

            count = 0;
            mid = (l + r) / 2;
            UP(i, 0, n-1)
                count += (int)(rr[i]/mid);


            if (count >= f)
                l = mid;
            else
                r = mid;


        }

        printf("%.4lf\n", mid);
    }
    return 0;
}


// double pie[10010];
// double sum,maxn;
// int main()
// {
//     int i,n,f,t,c,cnt;
//     double l,r,m;
//     //freopen("out.txt","r",stdout);
//     scanf("%d",&t);
//     while(t--)
//     {
//       scanf("%d%d",&n,&f);
//       f++;
//       maxn=sum=0;
//       for(i=0;i<n;i++)
//       {
//          scanf("%d",&c);
//          pie[i]=pi*c*c;
//          maxn=max(pie[i],maxn);
//          sum+=pie[i];
//       }
//       l=maxn/f;
//       r=sum/f;
//       while(l+0.00001<r)
//       {
//         m=(l+r)/2;
//         cnt=0;
//         for(i=0;i<n;i++)
//           cnt+=(int)floor(pie[i]/m);
//         if(cnt<f) r=m;
//         else l=m;
//       }
//       printf("%.4lf\n",l);
//     }
//     return 0;
// }


