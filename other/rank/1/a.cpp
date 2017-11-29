/********************************************************************
* File Name: a.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 六  8/26 14:24:50 2017
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

int num[100010];

int main() {
	int n;
	cin >> n;
	int sum = 0;
	int zheng, fu;
	zheng = MAX;
	fu = -MAX;

	for(int i = 0; i < n; i++) {
		cin >> num[i];
	}

	for(int i = 0;i < n;i++){
        if(num[i] > 0){
            sum += num[i];            
            if(num[i] % 2)	zheng = min(zheng, num[i]);
        }
        else if(num[i] < 0) {
            if(num[i] % 2)	fu = max(fu, num[i]); 
    	}
    }

    if(sum % 2)	cout << sum << endl;
    else{
    	cout << max(sum - zheng, sum + fu) << endl;
    }

   
}