#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;
int num[100];
int main()
{

    int n,k,c=0;
    cin>>n>>k;
    if(k==1)
    {
        cout<<n<<endl;
        return 0;
    }
    for(int i=2; n!=1; i++)
    {
        if(n%i==0)
        {
            n/=i;
            num[c++]=i;
            if(c==k)
            {
                for(int j=0;j<k-1; j++)
                {
                    printf("%d ",num[j]);
                }
                printf("%d\n",n*num[c-1]);
                return 0;
            }
            i--;

        }
    }
    printf("-1\n");
}
