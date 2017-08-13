/********************************************************************
* File Name: famachengzhong.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 日  8/13 00:06:59 2017
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

bool dp[100005];
int fama[8] = {0, 1, 2, 3, 5, 10, 20};
int vis[8];
int count_;

void dfs(int weight) {
	if(weight > 1000) return;
	if(dp[weight] == true) {
		return;
	}
	else{
		dp[weight] = true;
	}	

	for(int i = 1; i <= 6; i++) {
		if(vis[i] > 0) {
			vis[i]--;
			dfs(weight+fama[i]);
			vis[i]++;
		}
	}
}


int main() {
	for(int i = 1; i <= 6; i++) {
		cin >> vis[i];
	}

	memset(dp, 0, sizeof(dp));
	count_ = 0;
	dfs(0);

	for(int i = 1; i <= 1000; i++) {
		if(dp[i]) {
			cout << i << endl;
			count_++;
		} 
	}
	cout << "Total=" << count_ << endl;
}