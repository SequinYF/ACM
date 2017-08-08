/********************************************************************
* File Name: Robberies.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 一  8/ 7 17:35:18 2017
*************************************************************************/

#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
using namespace std;
float p[102];
int m[102];
float dp[10002];

int main(){
	int t;
	cin >> t;
	while(t--){
		float pp;
		int n;
		int sum = 0;
		cin >> pp >> n;
		memset(dp, 0, sizeof(dp));
		memset(p, 0, sizeof(p));
		memset(m, 0, sizeof(m));
		for(int i = 0; i < n; i++){
			cin >> m[i] >> p[i];
			sum += m[i];
		}

		dp[0] = 1.0;
		for(int i = 0; i < n; i++){
			for(int j = sum; j >= m[i]; j--){
				dp[j] = max(dp[j], dp[j-m[i]]*(1-p[i]));
			}
		}
		for(int i = sum; i >= 0; i--){
			if(dp[i] >=1-pp) {
				cout << i << endl;
				break;	
			}
		}
	}
}