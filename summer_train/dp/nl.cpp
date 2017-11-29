/********************************************************************
* File Name: nl.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 二  8/ 8 19:20:12 2017
*************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
int a[100020];
pair<int, int> qu[100020];
int head, tail;
int main(){
	int n, L;
	cin >> n >> L;

	for (int i = 1; i <= n; ++i)
	{
		cin >> >>;
	}
	head = tail = 1;

	qu[1] = make_pair(a[1], 1);
	for (int i = 2; i <= L; ++i)
	{
		while(a[i] > qu[tail].first && tail >= head)
			tail++;
		qu[++tail] = make_pair(a[i], i);
	}

	for (int i = L; i <= n; ++i)
	{
		cout << qu[head].first;
		while(qu[head].second < i-L+2 && head <= tail)
			tou++;
		while(a[i+1] > qu[tail].first && tail >= head)
			tail--;
		make_pair(a[i], i+1);
	}

}