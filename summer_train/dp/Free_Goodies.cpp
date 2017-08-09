/********************************************************************
* File Name: Free_Goodies.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 三  8/ 9 18:43:57 2017
*************************************************************************/
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
using namespace std;

struct node{
	int p, j;
};

node v[1001];

bool cmp(node const a, node const b){
	if(a.p == b.p){
		return a.j < b.j;
	}
	return a.p > b.p;
}

int dp[1001][1001];
int cost[1001][1001];

int main(){
	int T;
	cin >> T;
	while(T--) {
		int n, sum;
		string name;
		cin >> n >> name;
		sum = 0;
		for (int i = 1; i <= n; ++i)
		{
			int a, b;
			cin >> v[i].p >> v[i].j;
			sum += v[i].p;
		}
		
		sort(v+1, v+n+1, cmp);
		int flag;
		flag = 0;
		if(name[0] == 'P') {
			flag = 1;
		}

		memset(dp, 0, sizeof(dp));
		memset(cost, 0, sizeof(cost));

		for(int i = 1; i <= n-flag; i++) {
			for(int j = 1; j <= (i+1)/2; j++) {
				if(dp[i-1][j] > dp[i-1][j-1]+v[i+flag].j){
					dp[i][j] = dp[i-1][j];
					cost[i][j] = cost[i-1][j];
				}
				else if(dp[i-1][j] == dp[i-1][j-1]+v[i+flag].j) {
					dp[i][j] = dp[i-1][j];
					cost[i][j] = min(cost[i-1][j], cost[i-1][j-1]+v[i+flag].p);
				}
				else{
					dp[i][j] = dp[i-1][j-1] + v[i+flag].j;
					cost[i][j] = cost[i-1][j-1] + v[i+flag].p;
				}
			}	
		}
		cout << sum - cost[n-flag][(n-flag+1)/2] << " " << dp[n-flag][(n-flag+1)/2] << endl;
	}
}