/********************************************************************
 * File Name: shuiguo.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 三  8/ 2 21:29:05 2017
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

struct info
{
    map <string, int> mm; 
};
int main()
{
    map <string, info> ma;       
    map <string, info>::iterator it;
    map <string, int>::iterator mmit;
    string name,place;
    int count;
    int n,t;
    cin >> t;
    while(t--)
    {
        ma.clear();
        cin >> n;
        while(n--)
        {
            cin>>name>>place>>count;
            ma[place].mm[name] += count;
        }
        for (it = ma.begin(); it != ma.end(); it++)
        {
            cout<<it->first<<endl;
            for (mmit = it->second.mm.begin(); mmit != it->second.mm.end(); mmit++)
            {
                
                cout<<"   |----"<<mmit->first<<"("<<mmit->second<<")"<<endl;
            }
        }
        if(t != 0)
            cout<<endl;
    }
    return 0;
}
