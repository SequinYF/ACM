#include<stdio.h>
#include<string.h>
#include <iostream>
using namespace std;
char a[1100],b[1100];
int main()
{
    int n;
    int len,llen;
    int i,j,k,l;
    cin >> n;
    getchar();
    while(n--)
    {
        gets(a);
        len=strlen(a);
        for(llen=0,i=0;i<len;i++)
        {
            if(a[i]!=' ')
            {
                b[llen]=a[i];
                llen++;
            }
            else
            {
                for(j=llen-1;j>=0;j--)
                    cout << b[j];
                cout << " ";
                llen=0;
            }
        }
        for(j=llen-1;j>=0;j--)
          cout << b[j];
        cout << endl;
    }
    return 0;
}
