/********************************************************************
* File Name: b.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 二  8/29 23:25:48 2017
*************************************************************************/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
	double R, d;
	cin >> R >> d;
	int n;
	cin >> n;
	int coun = 0;
	for(int i = 0; i < n; i++) {
		double x, y, r;
		cin >> x >> y >> r;
		double dis = sqrt(x*x*1.0 + y*y*1.0);
		//if(dis == R - r && dis == d + r) {
		//	coun++;
		//}
	//	if(f+len<=r&&f-len>=r-d) {
		if(dis >= R - d + r && dis <= R - r){
			coun++;
		}
	}

	cout << coun << endl;
}