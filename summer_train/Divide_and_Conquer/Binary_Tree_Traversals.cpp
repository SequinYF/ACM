/********************************************************************
* File Name: Binary_Tree_Traversals.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 四  8/ 3 17:01:07 2017
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
int n;
int p[1005];
int o[1005];

/*
void sousuo(int a,int b,int n,int flag)
{
    
    if(n==1)//如果存在左子树或右子树就直接输出
    {
        printf("%d ",t1[a]);
        return ;
    }
    else if(n<=0)//如果不存在左子树或右子树就返回上一层
        return ;
    int i;//继续罚分为左子树和右子树
    for(i=0;t1[a]!=t2[b+i];i++) ;//找到罚分点也就是根节点
    sousuo(a+1,b,i,0);//左子树的遍历
    sousuo(a+i+1,b+i+1,n-i-1,0);//右子树的遍历
    if(flag==1)//最原始的跟节点
        printf("%d",t1[a]);
    else//一般的根节点
        printf("%d ",t1[a]);
}*/

void func(int a, int b, int num, int d){
    if(num <= 0){
        return;
    }
    else if(num == 1){
        cout << p[a] << " ";
        return;
    }
    int i;
    //cout << node << endl;
    for(i = 0; o[b+i] != p[a]; i++);
      //      cout << i << endl;
    func(a+1, b, i, 0);
    func(a+i+1, b+i+1, num-i-1, 0);
    if(d){
        cout << p[a];
    }
    else
        cout << p[a] << " ";
  
}

int main(){
    while(cin >> n){
        int i;
        UP(i, 1, n){
            cin >> p[i];
        }
        UP(i, 1, n){
            cin >> o[i];
        }

        func(1, 1, n, 1);
        cout << endl;
    }
}



