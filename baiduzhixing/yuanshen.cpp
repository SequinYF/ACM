/********************************************************************
* File Name: yuanshen.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 六  8/12 16:38:54 2017
*************************************************************************/
#include <iostream>
#include <cstdio>
using namespace std;
int main() {
	int t;
	cin >> t;
	while(t--){
		int n;
	cin >> n;
	n--;

	long long ans = 0;
	long long tmp;

	for(long long i = 2; i * i <= n; i++) {
		if(n %i == 0) 
		{
			tmp = 0;
			while(n % i == 0) {
				tmp++, n/=i;
			}
			if(ans == 0) ans = tmp + 1;
			else ans *= (tmp + 1);
		}
	}
	if(n > 1) {
		if(ans == 0)	ans = 2;
		else ans *= 2;
	}

	cout << ans << endl;
}
}