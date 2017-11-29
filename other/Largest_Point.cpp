/********************************************************************
* File Name: Largest_Point.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 四  9/ 7 21:08:31 2017
*************************************************************************/

#include <cstdio>
#include <algorithm>
#include <cmath>
using namespace std;

#define ll long long

int main() {
    int t;
    scanf("%d", &t);
    for(int i = 1; i <= t; i++) {
        ll ret = 0;
        int n, a, b;
        scanf("%d %d %d", &n, &a, &b);

        for(int i = 0; i < n; i++) {
            int absnum, num;
            scanf("%d", &num);
            absnum = abs(num);

        }


:``



        printf("Case #%d: %lld", t, ret);
    }
}
