/********************************************************************
 * File Name: b1.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 日  8/13 14:12:11 2017
 *************************************************************************/

#include<iostream>
#include<cstring>
using namespace std;

#define ll long long

const int INF = 1e9+7;
const int MAX = 1000+10;

int fflag[3000], inde[3000], prime[MAX], sum_[MAX];
int count_ = 0;


void get_prime()
{
    for(int i = 2; i <= MAX;i++)
    {
        if(!fflag[i])
        {
            prime[count_++] = i;
            inde[i] = count_ - 1;
        }
        for(int j = 0;j < count_ && prime[j] * i <= MAX; j++)
        {
            fflag[prime[j] * i] = 1;
            inde[prime[j] * i] = j;
            if(i % prime[j] == 0)   break;
        }
    }
}

void func(int ro, int v)
{
    while(ro != 1)
    {
        sum_[inde[ro]]+=v;
        ro/=prime[inde[ro]];
    }
}

int main()
{

    get_prime();
    int T;
    int m, n;
    ll ret;
    cin >> T;
    while(T--) {
        ret = 1;
        cin >> n >>m;

        if(n < m)
            swap(n, m);

        memset(sum_ , 0, sizeof(sum_));

        for(int i = 2; i <= n; i++)
            func(i, 1);
        for(int i = 2; i <= m; i++)
            func(i, -1);
        for(int i = 2; i <= n-m; i++)
            func(i, -1);
        for(int i = 0; i < count_; i++)
            while(sum_[i])
            {
                ret = (ret * prime[i]) % INF;
                sum_[i]--;
            }
        cout<< ret <<endl;
    }
    return 0;
}
