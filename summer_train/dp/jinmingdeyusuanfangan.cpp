/********************************************************************
 * File Name: jinmingdeyusuanfangan.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 二  8/ 8 15:48:25 2017
 *************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
int dp[50000];
//int v[65][3];
//int p[65][3];
int v1[65],v2[65],v3[65];
int p1[65],p2[65],p3[65];
int main(){
    int n, m;
    while (cin >> n >> m)
    {
                    for(int j=0;j<65;j++)
            {
                v1[j]=v2[j]=v3[j]=0;
                p1[j]=p2[j]=p3[j]=0;
            }
        int ii = 1;
        for (int i = 1; i <= m; ++i)
        {
            
            int vv, pp, q;
            cin >> vv >> pp >> q;
            if(q == 0){
                v1[i]= vv;
                p1[i]= pp*vv;
            }
            else{
                if(v2[q] == 0){
                    v2[q] = vv;
                    p2[q] = pp*vv;
                }
                else{
                    v3[q] = vv;
                    p3[q] = pp*vv;
                }
            }
        }

//        for (int i = 1; i < ii; ++i)
//        {
//            for (int j = 0; j < 3; ++j)
//            {
//                cout << v[i][j] << " ";
//                cout << p[i][j] << " ";
//            }
//            cout << endl;
//        }

        memset(dp, 0, sizeof(dp));
        int maxn=0;
        for (int i = 1; i<=m; ++i)
        {
            if(v1[i]!=0)
            for (int j = n; j >= v1[i]; j--)
            {   
                int d= dp[j-v1[i]]+p1[i];
                dp[j] = max(dp[j], d);
                if(j >= v1[i]+v2[i])
                    dp[j] = max(dp[j], dp[j-v1[i]-v2[i]] + p1[i]+ p2[i]);

                if(j >= v1[i]+v3[i])
                    dp[j] = max(dp[j], dp[j-v1[i]-v3[i]] + p1[i] + p3[i]);

                if(j >= v1[i]+v2[i]+v3[i])
                    dp[j] = max(dp[j], dp[j-v1[i]-v2[i]-v3[i]] + p1[i] + p2[i] + p3[i]);
               
                maxn=max(dp[j],maxn);
            }
        }
        cout << dp[n]<< endl;
    }
}