/********************************************************************
 * File Name: Median.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 三  8/ 2 16:51:10 2017
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

ll x[100009];

// bool check(int x)
// {
//     int cnt = 0;
//     for(int i=0; i<n; i++)
//     {
//        int t=upper_bound(a,a+n,a[i]+x)-a;//比a[i]+x小的元素的个数
//        cnt+=(t-i-1);//排除a[i]之前的那些元素,共有i+1;
//     }
//     if(cnt>=temp) return true;  
//         else return false;
// }
// int main()
// {
//     while(scanf("%d",&n)!=EOF)
//     {
//          for(int i=0;i<n;i++)
//             scanf("%d",&a[i]);
//          sort(a,a+n);
//          int m=n*(n-1)/2;
//          temp=(m+1)/2;
//          int l=0,r=a[n-1]-a[0];
//          int ans;
//          while(l<=r)//二分搜索
//          {
//              int mid=(l+r)>>1;
//              if(check(mid))
//               ans=mid,r=mid-1;
//              else l=mid+1;
//          }
//          printf("%d\n",ans);
//     }
//     return 0;
// }

int main()
{
    int n;
    while(scanf("%d",&n) != EOF)
    {
        int i;
        UP(i, 0, n-1)
            scanf("%lld",&x[i]);
        sort(x, x+n);
        ll count = n * (n - 1)/2;
        ll temp = (count + 1)/2;
        ll l = 0, r = x[n-1] - x[0];
        ll ret, mid;
        ll tt;
        while(l <= r){
            ret = 0;
            mid = (l + r)/2;
            //cout << l << r << endl;
            UP(i, 0, n-1)
            {
                int sum = upper_bound(x, x + n, x[i] + mid) - x;
                ret += (sum - i - 1);
             //   cout << sum << "d" << ret << endl;
            }
            if(ret < temp)
                l = mid + 1;
            else if(ret >= temp){
            	tt = mid;
                r = mid - 1;
            } 
        }
        printf("%lld\n",tt);
    }
    return 0;
}


