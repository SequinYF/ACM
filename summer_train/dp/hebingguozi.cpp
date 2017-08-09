/********************************************************************
* File Name: hebingguozi.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 二  8/ 8 20:07:48 2017
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define INF 0x3f3f3f3f
int p[10005];
int guo[10005];
int main(){
	int n;
	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		cin >> guo[i];
	}
	if(n < 2){
		cout << 0 << endl;
		return 0;
	}
	memset(p, INF, sizeof(p));
	guo[n+1] = INF;
	sort(guo+1, guo+n+1); 
	p[1] = guo[1]+guo[2];
	int head, tail;
	head = tail = 1;
	int nn;
	int index = 3;
	int sum = p[1];
	p[2] = INF;

	for (int i = 3; i <= n; ++i)
	{	
		tail++;
		p[tail] = 0;
		for (int j = 0; j < 2; ++j)
		{	//cout << guo[index] << p[head] << endl;
			if(guo[index] > p[head] && head != tail) {
				p[tail] += p[head];
				head++;
			}
			else{
				p[tail] += guo[index];
				index++;
			}
		}
		sum += p[tail];
		p[tail+1] = INF;
		
	}

	cout << sum << endl;
}