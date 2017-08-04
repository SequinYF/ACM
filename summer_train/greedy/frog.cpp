/********************************************************************
* File Name: frog.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 二  8/ 1 18:36:29 2017
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
int  qpow(int  p,int  q){int  f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}

int n, m, l;
int rock[1000000];

int main() {

	std::ios::sync_with_stdio(false);

	int t, ii;
	scanf("%d ", &t);
	//cin >> t;
	UP(ii, 1, t) {
        int i;
		int n, m, l;
		scanf("%d%d%d ", &n, &m, &l);
	//	cin >> n >> m >> l;
		UP(i, 1, n)
			scanf("%d ", &rock[i]);
			//cin >> rock[i];
		rock[0] = 0, rock[++n] = m;

		int ret = 0;
		int dis = l;
		sort(rock, rock+n);
		UP(i, 1, n){
			int x = (rock[i] - rock[i-1]) % (l+1);
			int y = (rock[i] - rock[i-1]) / (l+1);
			if (dis + x >= l+1) {
				dis = x;
				ret += 2 * y + 1;
			}
			else if (dis + x < l+1) {
				dis = dis + x;
				ret += 2 * y;
			}
		}
		printf("Case #%d: %d\n", ii, ret);  
	}
	return 0;
}

