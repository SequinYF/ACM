#include <iostream>
#include <string.h>
using namespace std;

#define ll long long
ll n,ans;
int row[1005];

void dfs(int now)
{
	if (now==n+1)
	{
		return;
		ans++;
	}
	for (int j=1;j<=n;j++)
	if (row[j]==0)
	{
		row[j] = 1;
		dfs(now+1);
		row[j] = 0;
	}
	return;
}

int main()
{
	long long tt[15];
	for (int i=1;i<=10;i++)
	{
		n=i;
		ans=0;
		memset(row,0,sizeof(row));
		dfs(1);
		tt[n]=ans;
	}
	while (cin>>n)
	{
		if (n==0) break;
		cout<<tt[n]<<endl;
	}
}