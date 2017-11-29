/*******************************************************************
* File Name: c.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 六  8/26 15:42:58 2017
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
#define ll double 
#define MAX 10000005  
#define MOD 1000000007  
#define INF 1000000005  
#define EXP 1e-8  
#define lowbit(x) (x&-x)  
//ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}

struct NODE {
	int x,v;
}node[60005];

/*
int main() {
	int n;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> node[i].x;
	}
	for(int i = 0; i < n; i++) {
		cin >> node[i].v;
	}

	bool flag = true;
	ll l, r, m;
	l = 0; 
	r = INF * 1.0;
	ll point = 0;
	while((r - l )> 10e-6) {
		point = INF * 1.0;
		ll m = (r + l) * 1.0 / 2.0;
		//cout << m << " " << r-l << endl;
    	for(int i = 0; i < n; i++) {
    		ll t = node[i].x * 1.0 + node[i].v * 1.0 * m;
        	point = min(point, t);
        }
        cout << point << endl;
   		for(int i = 0; i < n; i++) {
        	if(point < node[i].x && (node[i].x * 1.0 - node[i].v * 1.0 * m) > point) {
        		flag = false;
        		cout << point << endl;
        		break;
        	}
        }

        if(flag)	r = m;
        else{
        	l = m;
        }	
    }

    cout << l << endl;
}
*/

int n;

bool fun(ll m) {

    ll point = INF * 1.0;
    for(int i = 0; i< n; i++)
        point = min(point, node[i].x * 1.0 + node[i].v * m * 1.0);
    for(int i = 0; i < n; i++) {
        if(node[i].x * 1.0 > point) {
            if(node[i].x * 1.0 - node[i].v * m * 1.0 > point)	return false;
        }
    }
    return true;
}

int main() {
	//ios::sync_with_stdio(false);
	scanf("%d", &n);
	for(int i = 0; i < n; i++) {
		scanf("%d", &node[i].x);
	}
	for(int i = 0; i < n; i++) {
		scanf("%d", &node[i].v);
	}
	ll l, r, m;
	l = 0; 
	r = INF;
	while(r-l > 0.0000001) {
		ll m = (r+l)/2.0;
		bool flag = fun(m);
        if(flag) {
        	r = m;
        }
        else{
        	l = m;
        }	
    }

    printf("%lf\n", l);
    return 0;
}
