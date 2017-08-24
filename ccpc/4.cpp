/********************************************************************
* File Name: 4.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 六  8/19 13:05:11 2017
*************************************************************************/

        /* kmp算法：
 * kmp()返回匹配数。
 * next[i]:ss的第i个位置前的最长与模式串ss前缀匹配的长度。
 * vis[i]:第i个位置是否被匹配。
 * 使用kmp()前必须调用pre_kpm();
 * 时间复杂度O(n+m)
 */

#include <iostream>
#include <string.h>
#include <algorithm>
#include <cstdio>
using namespace std;
#define MAXN 100005
#define MOD 1000000007
int nex[MAXN];
int vis[MAXN];
void pre_kmp(char ss[], int m)
{
    nex[0]=-1;
    int i=0,j=-1;
    while(i<m)
    {
        while(j!=-1&&ss[i]!=ss[j]) j=nex[j];
        nex[++i]=++j;
    }
}
int kmp(char str[],int len,char ss[],int m)
{
    memset(vis,0,sizeof vis);
    int i,j,cnt=0;
    i=j=0;
    while(i<len)
    {
        while(j!=-1&&str[i]!=ss[j]) j=nex[j];
        ++i;++j;
        if(j>=m) cnt++,j=nex[j],vis[i-1]=1;
    }
    return cnt;
}


int main() {
	int t;
	ios::sync_with_stdio(false);
	cin >> t;

	while(t--) {
		char s1[MAXN], s2[MAXN];
		cin >> s1 >> s2;
		int len1 = strlen(s1);
		int len2 = strlen(s2);
		long long len[MAXN];	
		long long sum = 0;
		reverse(s2, s2+len2);
		reverse(s1, s1+len1);

		for(int i = 0; i < len2; i++) {		
			pre_kmp(s2, len2 - i);
			int ret = kmp(s1, len1 , s2, len2 - i);
			len[i] = len2 - i;
			sum += (len[i]*ret) % MOD;
		}

		cout << sum << endl;
	}
}
