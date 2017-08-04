/********************************************************************
* File Name: inversion.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 四  8/ 3 19:05:38 2017
*************************************************************************/


#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stack>
#include <queue>
#include <map>
#include <ctype.h>
#include <set>
#include <vector>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <climits>
#include <string>
#include <list>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <sstream>
using namespace std;

#define lson 2*i
#define rson 2*i+1
#define LS l,mid,lson
#define RS mid+1,r,rson
#define UP(i,x,y) for(i=x;i<=y;i++)
#define DOWN(i,x,y) for(i=x;i>=y;i--)
#define MEM(a,x) memset(a,x,sizeof(a))
#define W(a) while(a)
#define gcd(a,b) __gcd(a,b)
#define pi acos(-1.0)
#define pii pair<int,int>
#define ll long long
#define MAX 1000005
#define MOD 1000000007
#define INF 0x3F3F3F3F
#define EXP 1e-8
#define lowbit(x) (x&-x)
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}

const long M=INF;
ll cnt;
int arry[100006];
int L[100006];
int R[100006];

void Merge(int A[],long Left,long Middle,long Right)
{
    long n1=Middle-Left+1;
    long n2=Right-Middle;



    long i,k;
    //分成左右数组
    for(i=0;i<n1;i++)
        L[i]=A[Left+i];
    for(i=0;i<n2;i++)
        R[i]=A[Middle+i+1];

    L[n1]=M; //哨兵
    R[n2]=M;

    i=0;
    long j=0;
    for(k=Left;k<=Right;k++)
    {
        //如果某一边先抵达哨兵，另一边一定是小于的
        if(L[i]<=R[j])
            A[k]=L[i++];

        else{
            A[k]=R[j++];
            cnt += n1-i;
        }
    }

}

void Merge_sort(int A[],long Left,long Right)
{
    long Middle;
    if(Left<Right)
    {
        Middle=(Left+Right)/2; 
        Merge_sort(A,Left,Middle);  // 二分分解左部分
        Merge_sort(A,Middle+1,Right); // 二分分解有部分
        Merge(A,Left,Middle,Right); //合并两部分
    }
}

int main() 
{	
	int n, k;
    while(cin >> n >> k){
    	cnt = 0;
    	int i;
    	UP(i, 0, n-1){
    		cin >> arry[i];
    	}
    	
    	Merge_sort(arry,0, n-1);

    	cout<<max(cnt-k, (ll)0)<< endl;
    
    }

   

    return 0; 
}

