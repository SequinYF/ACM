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
long long dp[65][50000];
long long v[65][3];
long long p[65][3];

int main(){
    int n, m;
    while (cin >> n >> m){
        int ii = 1;
        for (int i = 0; i < m; ++i)
        {
            long long vv, pp, q;
            cin >> vv >> pp >> q;
            if(q == 0){
                v[ii][0] = vv;
                p[ii][0] = pp*vv;
                ii++;
            }
            else{
                if(v[q][1] == 0){
                    v[q][1] = vv;
                    p[q][1] = pp*vv;
                }
                else{
                    v[q][2] = vv;
                    p[q][2] = pp*vv;
                }
            }
        }

        for (int i = 1; i < ii; ++i)
        {
            for (int j = 0; j < 3; ++j)
            {
                cout << v[i][j] << " ";
                cout << p[i][j] << " ";
            }
            cout << endl;
        }

        memset(dp, 0, sizeof(dp));

        for (int i = 1; i < ii; ++i)
        {
            for (int j = n; j >= v[i][0]; j--)
            {   
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-v[i][0]] + p[i][0]);

                if(j >= v[i][0]+v[i][1])
                    dp[i][j] = max(dp[i][j], dp[i][j-v[i][0]-v[i][1]] + p[i][0] + p[i][1]);

                if(j >= v[i][0]+v[i][2])
                    dp[i][j] = max(dp[i][j], dp[i][j-v[i][0]-v[i][2]] + p[i][0] + p[i][2]);

                if(j >= v[i][0]+v[i][1]+v[i][2])
                    dp[i][j] = max(dp[i][j], dp[i][j-v[i][0]-v[i][1]-v[i][2]] + p[i][0] + p[i][1] + p[i][2]);
            
            }
        }
        cout << dp[ii-1][n] << endl;
    }
}

