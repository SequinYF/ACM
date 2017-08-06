#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int n,k,ans;
char s[10][10];
bool row[10];
void dfs(int now,int cnt)
{
	if(cnt==k){
		ans++;
		return ;
	}
	if(now==n) return;
	dfs(now+1,cnt);// 
	for(int j=0;j<n;j++){
		if(!row[j]&&s[now][j]=='#'){
			row[j]=1;
			dfs(now+1,cnt+1);//cnt++是错误的 
			row[j]=0;
		}
	}
	//return ;
}
int main()
{
	while(~scanf("%d%d",&n,&k)){
		getchar();
		memset(row,0,sizeof(row));
		if(n==-1&&k==-1) break;
		for(int i=0;i<n;i++)
			scanf("%s",s[i]); 
		ans=0;
		dfs(0,0);
		printf("%d\n",ans);
	}
	return 0;
}
/*
注意：一个'#'处有下子和不下子两种选择
*/ 