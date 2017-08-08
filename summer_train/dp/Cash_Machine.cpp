/********************************************************************
 * File Name: Cash_Machine.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 一  8/ 7 19:06:43 2017
 *************************************************************************/
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int dp[1000005];
int d[12];
int n[12];
int cash;

void ZeroOnePack(int cost){
    for(int i = cash; i >= cost; i--)
        dp[i] = max(dp[i], dp[i-cost] + cost);
}

void CompletePack(int cost){
    for(int i = cost; i <= cash; i++)
        dp[i] = max(dp[i], dp[i-cost] + cost);
}

void MultiplePack(int cost,int count){
    if(cost * count > cash)
        CompletePack(cost);
    else{
        int k = 1;
        while(k < count){
            ZeroOnePack(k * cost);
            count -= k;
            k *= 2;
        }
        ZeroOnePack(count * cost);
    }
}


int main(){
    int N;
    while(scanf("%d%d", &cash, &N) != EOF){
        for(int i = 1; i <= N; i++)
            scanf("%d%d", &n[i], &d[i]);           
        memset(dp , 0, sizeof(dp));
        for(int i = 1; i <= N; i++)
            MultiplePack(d[i], n[i]);
        printf("%d\n", dp[cash]);
    }
    return 0;
}
