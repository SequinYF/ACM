/********************************************************************
* File Name: 2d.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 日  8/27 19:37:56 2017
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
#define MAX 10000005  
#define MOD 1000000007  
#define INF 0x3f3f3f3f  
#define EXP 1e-8  
#define lowbit(x) (x&-x)  
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}

struct node{
	int s, e;
	int num;
};


bool cmp(node &a, node &b) {
	return a.e > b.e;
}

int main() {
	int n;
	cin >> n;
	node event[n+1];
	for(int i = 0; i < n; i++) {
		cin >> event[i].s >> event[i].e;
		event[i].num = 0;
	}

	sort(event, event+n, cmp);
	int ret = 0;
	 for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j <n; ++j)
        {
           if(event[i].s < event[j].s){
           	event[i].num++;
           	ret = max(ret, event[i].num);
           }
        }
    }
    cout << ret << endl;
}