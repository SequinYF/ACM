/********************************************************************
 * File Name: 9_10shenyangA.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 日  9/10 12:22:43 2017
 *************************************************************************/
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;
const int N = 1e5+10;
const int Inf = 1<<30;
int a[N], dp[N];
int t, n;
int main(){
    scanf("%d",&t);
    while(t--) {
        int k;
        scanf("%d%d",&n, &k);
        for(int i = 0; i < n; i ++){
            scanf("%d",&a[i]);
            dp[i] = Inf;
        }
        for(int i = 0; i < n; i ++) {
            *upper_bound(dp,dp+n,a[i]) = a[i];
        }
        int ans = upper_bound(dp,dp+n,Inf-1) - dp;
        for(int i = 0; i < n; i ++) dp[i] = Inf;
        for(int i = 0; i < n/2; i ++){
            swap(a[i],a[n-i-1]);
        }
        for(int i = 0; i < n; i ++) {
            *upper_bound(dp,dp+n,a[i]) = a[i];
        }
        int ans1 = upper_bound(dp,dp+n,Inf-1) - dp;
        if(ans >= n-k || ans1 >= n-k) cout << "A is a magic array.\n";
        else cout << "A is not a magic array.\n";
        memset(a,0,sizeof(a));
    }
    return 0;
}
