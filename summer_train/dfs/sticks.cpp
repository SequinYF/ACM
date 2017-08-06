#include <stdio.h>
#include <iostream>
#include <map>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
using namespace std;

int sticks[100];
int factor[40000];
int vis[100];
bool prime[40000];

int stick_kind;
int stick_coun;
int sum;
int max_stick;
bool flag;

bool cmpbtol(int const a, int const b){
	return a > b;
}

void do_prime(){	
	for(int i = 2; i <= 3200; i++){
		prime[i] = 1;	//1:prime
		for(int j = 2; j*j <= i; j++){
			if(i % j == 0){
				prime[i] = 0; //not prime
				break;
			}
		}
	}
}

void make_factor(int start, int end){
	int j = 1;
	for(int i = start; i <= end; i++){
		if(end % i == 0){
			factor[j++] = i;
		}
	}
	factor[0] = j;	//[)
}

void dfs(int len, int now_sum, int step){
	if(!flag )
		return;
	if(step > stick_coun || now_sum > len)	return;
	if(now_sum == len){
		if(step == stick_coun){
			flag = false;
			printf("%d\n", now_sum);
			return;
		}
		dfs(len, 0, step);
		//cout << now_sum << step << endl;
		return;
	}

	for(int i = 0; i < stick_kind; i++){
		if(vis[sticks[i]] != 0){	//0: used all
			vis[sticks[i]]--;
			dfs(len, now_sum+sticks[i], step+1);
			vis[sticks[i]]++;
			if(flag){
				if(now_sum == 0 || now_sum + sticks[i] == len){	//剪枝三.四!!!!!!!!!!!!!!!!!!!
					break;
				}
			}
		}
	}
}

int main(){

	//freopen("sticks.txt", "r", stdin);
	//ios::sync_with_stdio(false);

	do_prime();
	while(scanf("%d", &stick_coun) && stick_coun){
		sum = 0;
		max_stick = -1;
		stick_kind = 0;
		int k = 0;
		memset(vis, 0, sizeof(vis));

		for (int i = 0; i < stick_coun; i++)
		{		//	取掉重复的 剪枝一
			int t;
			scanf("%d", &t);
			vis[t]++;
			sum += t;
			if(vis[t] > 1){	
				continue;	
			}else{
				sticks[k] = t;
				max_stick = max(sticks[k++], max_stick);	
			}		
		}
		stick_kind = k;	//[)

		if(stick_coun == 1)
			printf("%d\n", sticks[0]);
		else if(stick_coun == 2){
			if(vis[sticks[0]] == 2){
				//cout << sticks[0]<< endl;
				printf("%d\n", sticks[0]);
			}
			else
				printf("%d\n", sum);
		}
		else if(stick_coun == sum || sum == 1){
			printf("1\n");
		}
		else if(prime[sum])
			printf("%d\n", sum);
		else{
			flag = true;
			make_factor(max_stick, sum);
			sort(sticks, sticks+stick_kind, cmpbtol);	//剪枝二
			for(int i = 1; i < factor[0] && flag; i++){
				dfs(factor[i], 0, 0);
			}
		}
	}		
}

/*
9
15 3 2 11 4 1 8 8 8
9
5 2 1 5 2 1 5 2 1
4
1 2 3 4
64
40 40 30 35 35 26 15 40 40 40 40 40 40 40 40 40 40 40 40 40 40
40 40 43 42 42 41 10 4 40 40 40 40 40 40 40 40 40 40 40 40 40
40 25 39 46 40 10 4 40 40 37 18 17 16 15 40 40 40 40 40 40 40 40
*/