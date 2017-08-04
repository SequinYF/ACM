/********************************************************************
 * File Name: palace.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 四  8/ 3 19:35:36 2017
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
#define Up(i,x,y) for(i=x;i<=y;i++)
#define DOWN(i,x,y) for(i=x;i>=y;i--)
#define MEM(a,x) memset(a,x,sizeof(a))
#define W(a) while(a)
#define gcd(a,b) __gcd(a,b)
#define pi acos(-1.0)
#define pii pair<int,int>
#define ll long long
#define MAX 1000005
#define MOD 1000000007
//#define INF 0x3F3F3F3F
#define EXp 1e-8
#define lowbit(x) (x&-x)
ll qpow(ll p,ll q){ll f=1;while(q){if(q&1)f=f*p;p=p*p;q>>=1;}return f;}


//用类PointX和PointY表示依x坐标和y坐标排好序的点
class PointX {
    public:
        int operator<=(PointX a)const
        { return (x<=a.x); }
        int ID; //点编号
        ll x,y; //点坐标
};

class PointY {
    public:
        int operator<=(PointY a)const
        { return(y<=a.y); }
        int p; //同一点在数组x中的坐标
        ll x,y; //点坐标
};

template <class Type>
ll dis(const Type&u,const Type&v);

bool Cpair2(PointX X[], int n,PointX& a,PointX& b, ll& d);
void closest(PointX X[],PointY Y[],PointY Z[], int l, int r,PointX& a,PointX& b,ll& d);

template <typename Type>
void Copy(Type a[],Type b[], int left,int right);

template <class Type>
void Merge(Type c[],Type d[],int l,int m,int r);

template <class Type>
void MergeSort(Type a[],Type b[],int left,int right);

PointX X[100005];
PointX T[100005];
int main()
{
    //ios::sync_with_stdio(false);
    int num;
    scanf("%d", &num);
    W(num--){
        int length;
        scanf("%d", &length);

        for(int i=0;i<length;i++)
        {
            ll x, y;
            scanf("%lld%lld", &x, &y);
            X[i].ID=i;
            X[i].x=x;
            X[i].y=y;
        }

        PointX a;
        PointX b;
        PointX c;
        ll d;
        ll sum = 0;
        Cpair2(X,length,a,b,d);
        //cout<<"最邻近点对为：("<<a.x<<","<<a.y<<")和("<<b.x<<","<<b.y<<") "<<endl;
        c = b;
        sum = d*(length-2);
        int aa = 0;
        int bb = 0;

        for(int i=0;i<length;i++)
        {
            if(X[i].ID==a.ID){
                continue;
            }

            T[aa].ID = X[i].ID;
            T[aa].x = X[i].x;
            T[aa].y = X[i].y;
            aa++;
        }
        Cpair2(T,length-1,a,b,d);
      
        //cout<<"最邻近距离为： "<<d<<endl;
        //cout<<"最邻近点对为：("<<a.x<<","<<a.y<<")和("<<b.x<<","<<b.y<<") "<<endl;

        sum += d;
        for(int i=0;i<length;i++)
        {
            if(X[i].ID==c.ID){
                continue;
            }

            T[bb].ID = X[i].ID;
            T[bb].x = X[i].x;
            T[bb].y = X[i].y;
            bb++;
        }
        Cpair2(T,length-1,a,b,d);
        //cout<<"最邻近距离为： "<<d<<endl;
        //cout<<"最邻近点对为：("<<a.x<<","<<a.y<<")和("<<b.x<<","<<b.y<<") "<<endl;

        sum += d;

        printf("%lld\n", sum);
        // cout<<endl;
        // cout<<"最邻近点对为：("<<a.x<<","<<a.y<<")和("<<b.x<<","<<b.y<<") "<<endl;
        //cout<<"最邻近距离为： "<<d<<endl;
    }
    return 0;
}


//平面上任意两点u和v之间的距离可计算如下
    template <class Type>
inline ll dis(const Type& u,const Type& v)
{
    ll dx=u.x-v.x;
    ll dy=u.y-v.y;
    return dx*dx+dy*dy;
}

bool Cpair2(PointX X[], int n,PointX& a,PointX& b,ll& d)
{
    if(n<2) return false;

    PointX* tmpX = new PointX[n];
    MergeSort(X,tmpX,0,n-1);

    PointY* Y=new PointY[n];
    for(int i=0;i<n;i++) //将数组X中的点复制到数组Y中
    {
        Y[i].p=i;
        Y[i].x=X[i].x;
        Y[i].y=X[i].y;
    }

    PointY* tmpY = new PointY[n];
    MergeSort(Y,tmpY,0,n-1);

    PointY* Z=new PointY[n];
    closest(X,Y,Z,0,n-1,a,b,d);

    delete []Y;
    delete []Z;
    delete []tmpX;
    delete []tmpY;
    return true;
}
void closest(PointX X[],PointY Y[],PointY Z[], int l, int r,PointX& a,PointX& b,ll& d)
{
    if(r-l==1) //两点的情形
    {
        a=X[l];
        b=X[r];
        d=dis(X[l],X[r]);
        return;
    }

    if(r-l==2) //3点的情形
    {
        ll d1=dis(X[l],X[l+1]);
        ll d2=dis(X[l+1],X[r]);
        ll d3=dis(X[l],X[r]);

        if(d1<=d2 && d1<=d3)
        {
            a=X[l];
            b=X[l+1];
            d=d1;
            return;
        }

        if(d2<=d3)
        {
            a=X[l+1];
            b=X[r];
            d=d2;
        }
        else {
            a=X[l];
            b=X[r];
            d=d3;
        }
        return;
    }

    //多于3点的情形，用分治法
    int m=(l+r)/2;
    int f=l,g=m+1;

    //在算法预处理阶段，将数组X中的点依x坐标排序，将数组Y中的点依y坐标排序
    //算法分割阶段，将子数组X[l:r]均匀划分成两个不想交的子集，取m=(l+r)/2
    //X[l:m]和X[m+1:r]就是满足要求的分割。
    for(int i=l;i<=r;i++)
    {
        if(Y[i].p>m) Z[g++]=Y[i];
        else Z[f++]=Y[i];
    }

    closest(X,Z,Y,l,m,a,b,d);
    ll dr;

    PointX ar,br;
    closest(X,Z,Y,m+1,r,ar,br,dr);

    if(dr<d)
    {
        a=ar;
        b=br;
        d=dr;
    }

    Merge(Z,Y,l,m,r);//重构数组Y

    //d矩形条内的点置于Z中
    int k=l;
    for(int i=l;i<=r;i++)
    {
        if(fabs(X[m].x-Y[i].x)<d)
        {
            Z[k++]=Y[i];
        }
    }

    //搜索Z[l:k-1]
    for(int i=l;i<k;i++)
    {
        for(int j=i+1;j<k && Z[j].y-Z[i].y<d;j++)
        {
            ll dp=dis(Z[i],Z[j]);
            if(dp<d)
            {
                d=dp;
                a=X[Z[i].p];
                b=X[Z[j].p];
            }
        }
    }
}

    template <class Type>
void Merge(Type c[],Type d[],int l,int m,int r)
{
    int i = l,j = m + 1,k = l;
    while((i<=m)&&(j<=r))
    {
        if(c[i]<=c[j])
        {
            d[k++] = c[i++];
        }
        else
        {
            d[k++] = c[j++];
        }
    }

    if(i>m)
    {
        for(int q=j; q<=r; q++)
        {
            d[k++] = c[q];
        }
    }
    else
    {
        for(int q=i; q<=m; q++)
        {
            d[k++] = c[q];
        }
    }
}

    template <class Type>
void MergeSort(Type a[],Type b[],int left,int right)
{
    if(left<right)
    {
        int i = (left + right)/2;
        MergeSort(a,b,left,i);
        MergeSort(a,b,i+1,right);
        Merge(a,b,left,i,right);//合并到数组b
        Copy(a,b,left,right);//复制回数组a
    }
}

    template <typename Type>
void Copy(Type a[],Type b[], int left,int right)
{
    for(int i=left;i<=right;i++)
        a[i]=b[i];
}

