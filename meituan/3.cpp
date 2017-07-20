#include <iostream>
#include <string.h>
#include <cmath>
#include <set>
using namespace std;

set<int> ss;
set<int>::iterator it;
int main()
{
	int num;
	int m,x;
	char ch;
	int inpu[100005];
	int outpu[100005];
	while(cin >> m)
	{
		memset(inpu,0,sizeof(inpu));
		memset(outpu,0,sizeof(outpu));
		int ff =0 ;
		ss.clear();
		for(int i=1;i<=m;i++)
		{
			cin>>ch;
			if(ch=='?')
			{
				ss.insert(i);
			}
			else
			{
				cin >> x;
				if(ch=='I')
				{
					if(inpu[x])
					{
						it = ss.upper_bound(inpu[x]);
						if(ss.empty() || it==ss.end())
						{
							if(!ff)
							{
								ff =1 ;
								cout<<i<<endl;
							}
						}
						else
						{
							ss.erase(it);
						}
					}
					inpu[x]=i;
				}
				else
				{
					if(!inpu[x])
					{
						it = ss.upper_bound(outpu[x]);
						if(ss.empty() || it==ss.end())
						{
							if(!ff)
							{
								ff =1 ;
								cout<<i<<endl;
							}
						}
						else
						{
							ss.erase(it);
						}
					}
					inpu[x]= 0;
					outpu[x] = i;
				}
			}
		}

		if(!ff)
		{
			cout<<-1<<endl;
		}
	}
    return 0;
}
