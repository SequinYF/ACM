/********************************************************************
* File Name: 512.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 一  8/ 7 16:12:04 2017
*************************************************************************/
#include <iostream>
#include <stdlib.h>
#include <algorithm>
#include <string.h>
using namespace std;
int p[200003];
int h[200003];
int dp[101];

int main(){
	int C;
	cin >> C;
	while(C--){
		int m, n;
		cin >> n >> m;
		memset(dp, 0, sizeof(dp));
		memset(p, 0, sizeof(p));
		memset(h, 0, sizeof(h));
		int i = 0;
		while(m--)
		{	
			int a, b, c;
			cin >> a >> b >> c;
			while(c--){
				p[i] = a;
				h[i] = b;
				i++;
			}
		}

		int k;
		for(int ii = 0; ii < i; ii++)
				for(int k = n; k >= p[ii]; k--){
					dp[k] = max(dp[k], dp[k-p[ii]] + h[ii]);
				}


		cout << dp[n] << endl;
	}
}