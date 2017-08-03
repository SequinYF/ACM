/********************************************************************
 * File Name: 4_Values_whose_Sum_is_0.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 三  8/ 2 19:18:20 2017
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
#define UP(i,x,y) for(int i=x;i<=y;i++)
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

ll num[10000][10];
vector <ll> ss1, ss2;
int main(){
    int n;
    cin >> n;
        int i, j;

        UP(i, 1, n){
            UP(j, 1, 4){
                cin >> num[i][j];
            }
        }


        UP(i, 1, n){
            UP(j, 1, n){
                ll t =  num[i][1] + num[j][2];
                t = -t;
                ss1.push_back(t);
            }
        }
        UP(i, 1, n){
            UP(j, 1, n){
                ll t = num[i][3] + num[j][4];
                ss2.push_back(t);
            }
        }

        ll count = 0;

        sort(ss2.begin(), ss2.end());

        vector<ll>::iterator it;
        /*for(it = ss2.begin(); it != ss2.end();it++){
            cout << *it << endl;
        }
        */
        ll ret = 0;
        for(it = ss1.begin(); it != ss1.end(); it++){
            ll t = *it;
            // if(t == 0){
            //     continue;
            // }

            ret += upper_bound(ss2.begin(), ss2.end(), t) - lower_bound(ss2.begin(), ss2.end(), t);

            /*
            if(binary_search(ss2.begin(), ss2.end(), t)){
                //cout << t << endl;
                count++;
            }
            */
        }

        ss1.clear();
        ss2.clear();

        cout << ret << endl;

}
