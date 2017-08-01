/********************************************************************
 * File Name: a.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 一  7/31 22:44:06 2017
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
#define DOWN(i,x,y) for(i=x;i>= y; i++)
#define MEM(a,x) memset(a,x,sizeof(a))
#define W(a) while(a)
#define gcd(a,b) __gcd(a,b)
#define pi acos(-1.0)
#define pii pair<int,int>
#define ll long long
#define MAX 1000005
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define EXP 1e-8
#define lowbit(x) (x&-x)


int main(){
    ll s, v1,v2,t1,t2;
    while(cin >> s >> v1 >> v2 >> t1 >> t2){
        ll ret1 = t1 * 2 + v1 * s;
        ll ret2 = t2 * 2 + v2 * s;
        if(ret1 < ret2){
            cout << "First" << endl;
        }
        else if(ret1 > ret2){
            cout << "Second" << endl;
        }
        else{
            cout << "Friendship" << endl;
        }
    }
}
