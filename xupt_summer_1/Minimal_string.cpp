#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
using namespace std;
char s[100005];
int a[100005];
int idx[100005];
int main()
{
    while(~scanf("%s",s))
    {
        int n=strlen(s);
        memset(idx,0,sizeof(idx));
        for(int i=0;i<n;i++)
          a[i]=s[i]-'a'+1;
        for(int i=n-1;i>=0;i--)
        {
            if(i==n-1)
              idx[i]=a[i];
            else
              idx[i]=min(idx[i+1],a[i]);
        }

        stack<char >t;

        for(int i=0;i<n;i++)
        {
            if(t.size()==0)
            {
                t.push(s[i]);
            }
            else
            {
                while(!t.empty())
                {
                    int u=t.top()-'a'+1;
                    if(u<=idx[i])
                    {
                        cout << t.top();
                        t.pop();
                    }
                    else break;
                }
                t.push(s[i]);
            }
        }
        while(!t.empty())
        {
            cout << t.top();
            t.pop();
        }
        cout << endl;
    }
}
