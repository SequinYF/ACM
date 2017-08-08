/********************************************************************
* File Name: lanjiedaodan.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 二  8/ 8 09:26:02 2017
*************************************************************************/

#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;
int dao[10002];
int dp[10002];
int main(){
	int n;
	while(cin >> n && n){
		for (int i = 0; i < n; ++i)
		{
			cin >> dao[i];
		}
		//memset(dp, 1, sizeof(dp));
		for (int i = 0; i < n; ++i)
		{
			dp[i] = 1;
		}

// 3890  2070  1550  3000  2990  1700  1580  650

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < i ; ++j)
			{
				if(dao[j] >= dao[i])
					dp[i] = max(dp[i], dp[j]+1);
				}
		}
	
			cout << dp[n-1] << endl;
	}
	


}