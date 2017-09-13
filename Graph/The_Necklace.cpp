/********************************************************************
* File Name: The_Monocycle.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 三  9/13 18:06:12 2017
*************************************************************************/
#include <iostream>
#include <cstdio>
#include <string.h>
#include <algorithm>
using namespace std;

int mmap[55][55];
int num[55];
int n;
int cas = 1;

void dfs(int x) {
    for(int i = 1; i <= 50; i++ ) {
        if(mmap[x][i]) {
            mmap[x][i]--;
            mmap[i][x]--;
            dfs(i);
            printf("%d %d\n", i, x);
        }
    }
}

int main() {
    int T;
    scanf("%d", &T);
    while(T--) {
        int n;
        scanf("%d", &n);

        memset(mmap, 0, sizeof(mmap));
        memset(num, 0, sizeof(num));
        for(int i = 0; i < n; i++) {
            int a, b;
            scanf("%d%d", &a, &b);
            mmap[a][b]++;
            mmap[b][a]++;
            num[a]++;
            num[b]++;
        }

        bool flag = true;
        int mmax = 0;
        int mi = 0;
        for(int i = 1; i <= 50; i++ ) {
            if(num[i] % 2 == 1){
                flag = 0;
                break;
            }
            else if(mmax < num[i]){
                mmax = num[i];
                mi = i;
            }
        }

        printf("Case #%d\n", cas++);
        if(flag){
            dfs(mi);
        }
        else{
            puts("some beads may be lost");
        }
        if(T > 0) {
        	puts("");
        }
    }

    return 0;
}
