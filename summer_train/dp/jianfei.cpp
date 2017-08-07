/********************************************************************
* File Name: jianfei.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 一  8/ 7 16:58:56 2017
*************************************************************************/
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
using namespace std;

int a[101];
int b[101];
int dp[100001];

int main()
{	
	int c;
	while(cin >> c){

		memset(dp, 0, sizeof(dp));
	memset(a, 0, sizeof(a));
	memset(b, 0, sizeof(b));
		for (int i = 0; i < c; ++i)
		{
			cin >> a[i] >> b[i];
		}
		int m;
		cin >> m;

		for (int i = 0; i < c; ++i)
		{
			for(int j = b[i]; j <= m; j++){
				dp[j] = max(dp[j], dp[j-b[i]] + a[i]);
			}
		}

		cout << dp[m] << endl;
	}
}