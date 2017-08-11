/********************************************************************
* File Name: ab_+_cd.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 五  8/11 20:29:24 2017
*************************************************************************/

#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

int main(){
	int T;
	cin >> T;
	while(T--) {
		int a, b, c, d, num, den;
		cin >> a >> b >> c >> d;
		den = b * d;
		num = a * d + b * c;

		int gcd = __gcd(den, num);
		cout << num/gcd << " " << den/gcd << endl; 
	}
}