/********************************************************************
* File name: nengliangxiangliang.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 四  8/10 19:41:11 2017
*************************************************************************/
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define ll int
#define INF 0x7FFFFFFF

struct node {
	ll s, e;
};
node power[2000];
ll dp[2005][2005];

int main() {
	int n;
	cin >> n;
	//while(cin >> n) {
		for(int i = 1; i <= n; i++) {
			cin >> power[i].s;
		}

		for(int i = n+1; i <= 2*n; i++) {
			power[i].s = power[i-n].s;
			power[i-n].e = power[i-n+1].s;
			power[i].e = power[i-n+1].s;
		}

		// for(int i = 1; i <= 2*n; i++) {
		// 	cout << power[i].s << " " << power[i].e << endl;
		// }

		memset(dp, 0, sizeof(dp));
		
		for(int len = 2; len <= 2 * n; len++) {
			for(int i = 1; i + len <= 2 * n + 1; i++) {
				int e = len + i - 1;
				for(int j = i; j < len + i - 1; j++) {				
					dp[i][e] = max(dp[i][e], dp[i][j] + dp[j+1][e] + power[i].s \
											* power[j].e * power[e].e);
					//cout << power[i].s << power[j].e  << power[e].e<< endl; 
				}
			}
		}
		ll temp = -INF;
		for(int i = 1; i <= n; i++) {
			temp = max(temp, dp[i][i+n-1]);
		//	cout << i << i+n-1 << " " << temp << endl;
		}
		
		cout << temp << endl;
	//}
	return 0;
}