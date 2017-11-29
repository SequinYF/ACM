/********************************************************************
* File Name: e.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 六  8/26 16:44:57 2017
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

string a, b;

int coun[MAX];
int num[MAX];

int main() {
    while(cin >> a >> b) {
       
        MEM(coun,0);
        MEM(num,0);
        
        int la = a.length();
        int lb = b.length();

    	for(int i = 0; i < la; i++) {
            num[a[i]]++;
        }
       	for(int i = 0; i < lb; i++) {
            coun[b[i]]++;
        }

        int temp = INF;
        for(int i = 0;i < 300; i++) {
            if(coun[i] > 0) {
                temp = min(temp, num[i]/coun[i]);
            }
        }

        for(int i = 0;i < 300; i++) {
            if(coun[i] > 0) {
                num[i] -= coun[i] * temp;
            }
        }
        int now = 0;
        for(int i = 0;i < la; i++) {
            if(a[i] == '?') {
                W(1) {
                    int flag = 0;
                    if(coun[now] == 0)	now++;
                    else {
                        if(num[now]<coun[now]) {
                            num[now]++;
                            flag = 1;
                            a[i] = now;
                        }
                        if(num[now] >= coun[now]) {
                            num[now] -= coun[now];
                            now++;
                        }
                    }
                    if(now >= 300)	now = 0;
                    if(flag == 1) break;
                }
            }
        }
        for(int i = 0; i < la; i++)
        {
            cout << a[i];
        }
        cout << endl;
    }
}

 