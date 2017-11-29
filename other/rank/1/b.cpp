/********************************************************************
* File Name: b.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 六  8/26 15:16:06 2017
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
#define MAX 100005  
#define MOD 1000000007  
#define INF 0x3f3f3f3f  
#define EXP 1e-8  
#define lowbit(x) (x&-x)  
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}

int main() {
	int n, k;
	cin >> n >> k;
   	int j;
   	int fac[MAX];
    for(int i = 2; n != 1; i++) {  
        if(n % i == 0)  
        {  
            n /= i;  
            fac[j] = i;	j++;  
            if(j == k) {  
                for(int j = 0;j < k - 1; j++) {  
                    cout << fac[j] << endl;  
                }  
                cout << fac[j-1] * n << endl;
                return 0;  
            }  
            i--;  
        }  
    }  
    cout << -1 << endl;
}