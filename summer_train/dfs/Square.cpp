/********************************************************************
* File Name: Square.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 日  8/ 6 23:28:01 2017
*************************************************************************/
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define INF 1e9+7
using namespace std;
ll sticks[25];
bool vis[25];
ll max_sum;
bool flag;
int M;

bool cmpbtol(int const a, int const	b){
	return a > b;
}

void dfs(ll len, ll now, int rest){
	if(len < now)	return;
	if(rest == 0){
		cout << "YES" << endl;
		flag = false;
		return;
	}
	if(now == len){
		dfs(len, 0, rest-1);
			return;
	}
	int pre;
	for(int i = 0; i < M && flag; i++){
		if(vis[i])	continue;
		if(now + sticks[i] > len){
			pre = sticks[i];
			continue;
		}
		while(pre == sticks[i])	continue;
		
		vis[i] = 1;
		dfs(len, now+sticks[i], rest);
		vis[i] = 0;
			if(now == 0 || now+sticks[i] == len){
			break;
		}
			
	}
}


int main(){
	int N;
	cin >> N;
	while(N--){
		cin >> M;
		if(M < 4)	flag = false;
		ll t[10002];
		memset(t, 0, sizeof(t));
		max_sum = 0;
		flag = true;

		for(int i = 0; i < M; i++){
			cin >> sticks[i];
			if(t[sticks[i]] < 4){
				t[sticks[i]]++;
				max_sum += sticks[i];
			}else{
				flag = false;
			}
			vis[i] = 0;
		}

		if(max_sum%4){
			cout << "NO" << endl;
			continue;
		}

		sort(sticks, sticks+M, cmpbtol);
		
		for(ll i = sticks[0]; i <= max_sum/4 && flag; i++){
			dfs(i, 0, 4);
		}
		
		if(flag){
			cout << "NO" << endl;
		}
	}
	return 0;
}