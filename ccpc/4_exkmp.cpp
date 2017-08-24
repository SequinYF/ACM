/********************************************************************
* File Name: 4_exkmp.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 六  8/19 14:30:25 2017
*************************************************************************/
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
const int maxn=1e6+5;
const int mod=1000000007;
int nxt[maxn],extend[maxn];
void pre_EKMP(char x[],int m)
{
    nxt[0]=m;
    int j=0;
    while(j+1<m && x[j]==x[j+1])j++;
    nxt[1]=j;
    int k=1;
    for(int i=2; i<m; i++)
    {
        int p=nxt[k]+k-1;
        int L=nxt[i-k];
        if(i+L<p+1)nxt[i]=L;
        else
        {
            j=max(0,p-i+1);
            while(i+j<m && x[i+j]==x[j])j++;
            nxt[i]=j;
            k=i;
        }
    }
}
void EKMP(char x[],int m,char y[],int n)
{
    pre_EKMP(x,m);
    int j=0;
    while(j<n && j<m && x[j]==y[j])j++;
    extend[0]=j;
    int k=0;
    for(int i=1; i<n; i++)
    {
        int p=extend[k]+k-1;
        int L=nxt[i-k];
        if(i+L<p+1)extend[i]=L;
        else
        {
            j=max(0,p-i+1);
            while(i+j<n && j<m && y[i+j]==x[j])j++;
            extend[i]=j;
            k=i;
        }
    }
}

char s1[maxn], s2[maxn];

int main() {
	int t;
	ios::sync_with_stdio(false);
	cin >> t;
	while(t--) {
		cin >> s1 >> s2;
		int len1 = strlen(s1);
		int len2 = strlen(s2);	
		reverse(s2, s2+len2);
		reverse(s1, s1+len1);
		EKMP(s2, len2, s1, len1);
		long long int ans=0;
        for(int i=0;i<len1;i++)
            ans=(ans+1ll*(1+extend[i])*extend[i]/2)%mod;
        cout << ans << endl;
	}
}
