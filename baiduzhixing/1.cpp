/********************************************************************
 * File Name: 1.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 六  8/12 14:14:01 2017
 *************************************************************************/

#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

#define MAX 1e9+7

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
typedef long long LL;
LL prime[1000100];
bool IsPrime[1000100];
int num;
void init_prime()
{
    num=0;
    memset(IsPrime,false,sizeof(IsPrime));
    for(LL i=2;i<=1000000;i++)
    {
        if(IsPrime[i]) continue;
        prime[num++]=i;
        for(LL j=i+i;j<=1000000;j+=i)
            IsPrime[j]=true;
    }
}

LL solve(LL n)
{
    LL ans=1,sum;
    for(int i=0;i<num&&prime[i]*prime[i]<=n;i++)
    {
        LL tmp=prime[i];
        sum=0;
        if(n%tmp==0)
        {
            while(n%tmp==0)
            {
                n/=tmp;
                sum++;
            }
            ans*=(sum+1LL);
        }
    }
    if(n>1) ans*=2;
    return ans-1;
}

int main()
{
    int T;
    LL n;
    init_prime();
    scanf("%d",&T);
    while(T--)
    {
        scanf("%I64d",&n);
        printf("%I64d\n",solve(n-1)+1);
    }
    return 0;
}