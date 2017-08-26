/********************************************************************
* File Name: aa.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 五  8/25 00:33:21 2017
*************************************************************************/


#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;

map <char, int> mm;
int main() {
	char s[1001];
	cin >> s;
	int i = 0;
	int num = 0;
	int ret = 0;
	
	// for (int i = 0; i < 26; ++i)
	// {
	// 	char ch = 'a'+i;
	// 	mm[ch] = 0;
	// }

	for(int i = 0; i < strlen(s); i++){
		
		if(mm[s[i]] == 0) {
			num++;
		}
		mm[s[i]] += 1;
		if(mm[s[i]] > 1) {
			ret++;
		}
	}

	int k; 
	cin >> k;
	if(num >= k) {
		cout << 0 << endl;
	}
	else if (num + ret >= k) {
		cout << k - num << endl;
	}
	else {
		cout << "impossible" << endl;
	}

	return 0;

}