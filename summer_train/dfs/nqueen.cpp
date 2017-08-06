#include <iostream>
#include <string.h>
using namespace std;
int n,ans;
int row[105],pie[105],na[105];

void dfs(int now)
{
	if (now==n+1)
	{
		ans++;
		return;
	}
	for (int j=1;j<=n;j++)
	if (row[j]==0 && pie[j+now]==0 && na[j-now+50]==0)
	{
		row[j]=pie[j+now]=na[j-now+50]=1;
		dfs(now+1);
		row[j]=pie[j+now]=na[j-now+50]=0;
	}
	return;
}

int main()
{
	int tt[15];
	for (int i=1;i<=10;i++)
	{
		n=i;
		ans=0;
		memset(row,0,sizeof(row));
		memset(pie,0,sizeof(pie));
		memset(na,0,sizeof(na));
		dfs(1);
		tt[n]=ans;
	}
	while (cin>>n)
	{
		if (n==0) break;
		cout<<tt[n]<<endl;
	}
}