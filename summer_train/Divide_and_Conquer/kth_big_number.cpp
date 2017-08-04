/********************************************************************
 * File Name: kth_big_number.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 四  8/ 3 15:06:51 2017
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
#define lolo long long
#define MAX 1000005
#define MOD 1000000007
#define INF 0x3F3F3F3F
#define EXP 1e-8
#define lowbit(x) (x&-x)
//ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}
/*
   int Scan()     //输入外挂
   {
   int res=0,ch,flag=0;
   if((ch=getchar())=='-')
   flag=1;
   else if(ch>='0'&&ch<='9')
   res=ch-'0';
   while((ch=getchar())>='0'&&ch<='9')
   res=res*10+ch-'0';
   return flag?-res:res;
   }
   void Out(int a)    //输出外挂
   {
   if(a>9)
   Out(a/10);
   putchar(a%10+'0');
   }

*/

int n, k;
int count = 0;
int a[6000000];
inline bool scan_d(int &ret)
{
    char c; int sgn;
    if (c = getchar(), c ==EOF) return 0;
    while (c != '-' && (c <'0' || c > '9')) c = getchar();
    sgn = (c == '-') ? -1 : 1;
    ret = (c == '-') ? 0 : (c - '0');
    while (c = getchar() , (c >= '0' && c <= '9'))
        ret = ret * 10  + (c - '0');
    ret *= sgn;
    return 1;
}
inline int findk(int l, int r, int k)
{

    if(l == r){
        return a[l];
    }
    int ll = l, rr = r;
    int kk = a[l];
    while(ll < rr){
        while(a[rr] <= kk && ll < rr)
            rr--;
        if(ll < rr)
            a[ll++] = a[rr];

        while(a[ll] >= kk && ll < rr)
            ll++;

        if(ll < rr){
            a[rr--] = a[ll];
        }
    }

    a[ll] = kk;
    if(ll > k){
        return findk(l, ll-1, k);
    }
    else if(ll < k){
        return findk(ll+1, r, k);
    }else{
        return a[ll];
    }
}

int main()
{
    scanf("%d%d", &n, &k);
    {
        getchar();
        for (int i = 1; i <= n; i++)
        {
            scan_d(a[i]);
        }
        int ret = findk(1, n, k);
        printf("%d\n", ret);
    }
    return 0;
}



