/********************************************************************
 * File Name: task.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 三  8/ 2 20:56:42 2017
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

struct node{
    int x, y;
}task[100005], mach[100005];

bool v1[100005];
bool v2[100005];

bool cmp(const node a, const node b){
    if(a.x == b.x){
        return a.y < b.y;
    }
    return a.x > b.x;
}

int main(){
    int n, m;
    while(cin >> n >> m){
        ll sum = 0;
        int i;
        UP(i, 0, n-1){
            cin >> task[i].x >> task[i].y;
        }
        UP(i, 0, m-1){
            cin >> mach[i].x >> mach[i].y;
        }

        sort(task, task+n, cmp);
        sort(mach, mach+m, cmp);
        int count = 0;
        UP(i, 0, m-1){
            ll mmin = INF;
            int index = -1;
            int j, r = 0;
            bool flag = false;
            while(!v1[r++]);
            while(task[r].x >= mach[i].x){
                r++;
            }
            UP(j, 0, r){
                if(mach[i].y > task[j].y){
                    continue;
                }


                if(!v1[j])
                    continue;
                if(task[j].y < mmin){
                    mmin = task[j].y;
                    index = j;
                    cout << j << endl;
                    flag = true;
                }
            }
            if(flag){

                cout << index << endl;
                v1[index] = false;
                ll temp = task[index].x*500 + 2*task[index].y;
                sum += temp;
                count++;
            }
        }

        cout << cout << " "<< sum << endl;
    }
}

#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
struct note
{
    int x,y;
}a[100005],b[100005];
bool cmp(note a,note b)
{
    if(a.x==b.x)
        return a.y>b.y;
    return a.x>b.x;
}
map<int,int>p;
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        for(int i=0;i<n;i++)
            scanf("%d%d",&a[i].x,&a[i].y);
        for(int i=0;i<m;i++)
            scanf("%d%d",&b[i].x,&b[i].y);
        sort(a,a+n,cmp);
        sort(b,b+m,cmp);
    int j=0,count=0;
    long long sum=0;
    p.clear();
    for(int i=0;i<m;i++)
    {
        while(j<n&&a[j].x>=b[i].x)
        {
            p[a[j].y]++;
            j++;
        }
        map<int,int>::iterator it=p.lower_bound(b[i].y);
        if(it!=p.end())
        {
            count++;
            sum+=(500*b[i].x+2*b[i].y);
            int t=it->first;
            p[t]--;
            if(p[t]==0)
                p.erase(t);
        }
    }
    printf("%d %I64d\n",count,sum);
    }
    return 0;
}
