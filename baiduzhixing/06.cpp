/********************************************************************
* File Name: 06.cpp
* Author: Daequin
* mail: Catherine199787@outlook.com
* Created Time: 日  8/13 15:20:43 2017
*************************************************************************/

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstdio>
#include <cstring>
#include <cmath>
using namespace std;
#define ll long long
#define MAX 100000+200

struct node {
    ll l,r;
};

int cmp(node a,node b)
{
    return a.l<b.l;
}

ll n, m;
vector < node > vec;
node pot;
ll Da[MAX];
ll len_[MAX];

int main()
{
    ios_base::sync_with_stdio(false);

	while(cin >> n >> m)
    {
        vec.clear();
        for(ll i = 1;i <= n; i++)
        {
            cin >> pot.l >> pot.r;
            vec.push_back(pot);
        }

        sort(vec.begin(), vec.end(), cmp);

		memset(Da, 0, sizeof(Da));

        ll cun_=0;
        Da[0] = 0;
        cun_ = vec[0].r ;
        for(int i = 1;i < n; i++)
        {
            if(vec[i].l <= cun_+1)
            {
                Da[i] = Da[i-1];
            }
            else
            {
                Da[i] = Da[i-1] + vec[i].l - cun_ - 1;
            }
            cun_ = max(vec[i].r, cun_);
        }
		len_[0] = vec[0].r;

        for(int i = 1;i < n; i++)
        {
            len_[i] = max(len_[i-1], vec[i].r);
        }

        int num;
		ll ret = 0;
        for(int i = 0;i < n; i++)
        {
            ll x = Da[i] + m;
            num = upper_bound(Da, Da+n, x) - Da;
            num--;
            ret= max(ret, len_[num] - vec[i].l + 1 + (m + Da[i] - Da[num]));
        }
        cout << ret <<endl;
    }
    return 0;
}