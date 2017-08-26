/********************************************************************
* File Name: bb.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 五  8/25 02:29:45 2017
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <string.h>
#include <cstdio>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
int n,m;
int a[55][55];
ll er[55];

int ct[55];
int ctc[55];
int main(int argc, const char * argv[]) 
{
	er[0] = 1;
	for(int i=1;i<=53;i++)
	{
		er[i] = er[i-1] * 2;
	}
	
	cin >> n >> m;
	for(int i = 0; i < n ; i++)
	{
		for(int j = 0; j < m ; j++)
		{
			cin >> a[i][j];
			if(a[i][j]) 
			{
				ct[i]++;
				ctc[j]++;
			}
		}
	}	
	ll ans = 0;
	for(int i=0;i<n;i++)
	{
		ans += er[ct[i]]-1-ct[i];
		ans += er[m-ct[i]]-1-(m-ct[i]);
	}
	
	for(int i=0;i<m;i++)
	{
		ans += er[ctc[i]]-1-ctc[i];
		ans += er[n-ctc[i]]-1-(n-ctc[i]);
	}
	ans+=n*m;
	cout << ans << endl;
	
	return 0;
}