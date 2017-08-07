/********************************************************************
* File Name: shuta.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 一  8/ 7 15:36:09 2017
*************************************************************************/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
using namespace std;
long long dp[502][502];

int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		memset(dp, 0, sizeof(dp));
		for(int i = 0; i < n; i++){
			for (int j = 0; j <= i; ++j)
			{
				cin >> dp[i][j];
			}
		}

		for(int i = n-2; i >= 0; i--){
			for(int j = 0; j <= i; j++){
				dp[i][j] += max(dp[i+1][j] , dp[i+1][j+1]);
			}
		}
		cout << dp[0][0] << endl;
	}
}