/********************************************************************
* File Name: 2c.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 日  8/27 18:35:59 2017
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
	int in;
	char ch;
};

char s[300050];
 node ques[300050];
int main() {
	int n, k;

//	ios::sync_with_stdio(false);
	scanf("%d%d", &n, &k);
	getchar();
	int coun = 0;
	scanf("%c", &s[1]);
//	cout << s << endl;
	for(int i = 2; i <= n; i++) {
		scanf("%c", &s[i]);
		if(s[i] == '.' && s[i-1] == '.') {
			coun++;
		}
	}
	
	// for(int i = 1; i <= k; i++) {
	// 	cin >> ques[i].in >> ques[i].ch;
	// }
	//func();
	
	getchar();
	int ret = coun;
	for(int i = 1; i <= k; i++) {
		scanf("%d %c", &ques[i].in, &ques[i].ch);
		//if(ques[i].ch == '.' && s[ques[i].in] == '.')	cout << coun << endl;
		//else if(ques[i].ch != '.' && s[ques[i].in] != '.')	cout << coun << endl;
		if(ques[i].ch == '.') {
			if(s[ques[i].in] != '.') {
				if(ques[i].in > 1)
					if(s[ques[i].in-1] == '.')	coun++;
				if(ques[i].in < n)
					if(s[ques[i].in+1] == '.')	coun++;
			}
			//cout << coun << endl;
		}

		else if(ques[i].ch != '.') {
			if(s[ques[i].in] == '.') {
				if(ques[i].in > 1)
					if(s[ques[i].in-1] == '.')	{
						coun--;
				//		cout<< "f" <<coun << endl; 
					}
				if(ques[i].in < n)
				//	cout << ques[i].in << "fds"<< endl;
					if(s[ques[i].in+1] == '.'){
						coun--;
				//		cout << "df"<< coun << endl; 
					}	
			}
			//cout << coun << endl;
		}

		printf("%d\n", coun);
		s[ques[i].in] = ques[i].ch;
	}
	return 0;
}
