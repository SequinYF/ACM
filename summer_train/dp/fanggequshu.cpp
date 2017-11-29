/********************************************************************
* File Name: fanggequshu.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 三  8/ 9 16:30:34 2017
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int path[12][12];
int dp[200][12][12];

int main(){
	int n;
	while(cin >> n){
		memset(path, 0, sizeof(path));
		int i, j, v;
		while(cin >> i >> j >> v && i + j + v) 
			path[i][j] = v;

		memset(dp, 0, sizeof(dp));
		for (int k = 1; k <= n*2-1; ++k)
			for(int i = 1; i <= k; i++)
				for(int j = 1; j <= k; j++) {
					dp[k][i][j] = max(dp[k][i][j], dp[k-1][i-1][j-1]);
					dp[k][i][j] = max(dp[k][i][j], dp[k-1][i-1][j]);  
                    dp[k][i][j] = max(dp[k][i][j], dp[k-1][i][j-1]);  
                    dp[k][i][j] = max(dp[k][i][j], dp[k-1][i][j]); 

					if(i == j)
						dp[k][i][j] += path[i][k-i+1];
					else
						dp[k][i][j] += path[i][k-i+1] + path[j][k-j+1];
				}

		cout << dp[2*n-1][n][n] << endl;
	}		
}