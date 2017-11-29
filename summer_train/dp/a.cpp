 #include"stdio.h"
int  a[7];
int  f[7][1001]={0};
int  m[7]={0,1,2,3,5,10,20};
int main()
{
    int i,j,k;
    int ans=0;
    f[0][0]=1;
    for(i=1;i<=6;i++)
     scanf("%d",&a[i]);
    for(i=1;i<=6;i++)
     for(j=0;j<=1000;j++)
      for(k=0;k<=a[i];k++)
       if(j>=k*m[i])
        f[i][j]=f[i][j]|f[i-1][j-k*m[i]];
    for(i=1;i<=1000;i++)
     ans+=f[6][i];
    printf("%ld\n",ans);
    return 0;
}   
