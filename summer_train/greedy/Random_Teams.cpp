/********************************************************************
 * File Name: Random_Teams.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 四  9/ 7 18:05:32 2017
 *************************************************************************/
#include <cstdio>
#include <string.h>
#define ll long long

int main() {
    ll n, m;
    scanf("%lld %lld", &n, &m);
    //scanf("%I64d %I64d", &n, &m);
    ll mmax = n-m+1;
    ll mmin = n/m;
    ll my = n % m;
    ll kmin = 0;
    ll kmax = 0;
    ll t = 0;

    if(m == n){
        printf("0 0\n");
        return 0;
    }

    ll x = mmin + 1;
    kmin += (my)*(x)*(x-1)/2 + (m-my)*(mmin)*(mmin-1)/2;

    kmax = (n-m+1)*(n-m)/2;

    printf("%lld %lld\n", kmin, kmax);
   // printf("%I64d %I64d\n", kmin, kmax);
}
