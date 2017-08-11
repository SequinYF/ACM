/********************************************************************
* File Name: prim.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 五  8/11 18:13:19 2017
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

#define INF 0x7FFFFFFF

bool notprime[10000];
int factor[100000];
int prime[100000], pindex;

void prime_func(int n) {

	pindex = 0;
	notprime[1] = 1;
	for(int i = 2; i < n; i++) {
		if(!notprime[i]) {
			prime[pindex++] = i;
		}
		for(int j = 0; j < pindex && prime[j] * i < n; j++) {
			notprime[i * prime[j]] = 1;
			if(i % prime[j] == 0)	break;
		}
	}
}



int main() {
	int N;
	prime_func(100000);
	while(cin >> N) {
		int n = N;
		int findex = 0;
		memset(factor, 0, sizeof(factor));
		for(int i = 0; i < pindex && prime[i] <= n; i++) {
			if(n % prime[i] == 0) {
				factor[findex] = prime[i];
				while(n % prime[i] == 0) {
					n /= prime[i];
				}
				findex++;
			}
			if(n > 1) {
				factor[findex] = n;
				findex++;
			}
		}


		if(N == 1)
			cout << 0 << endl;
		else
			cout << findex << endl;
	}
}