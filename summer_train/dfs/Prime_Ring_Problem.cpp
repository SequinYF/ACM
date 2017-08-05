/********************************************************************
 * File Name: Prime_Ring_Problem.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 五  8/ 4 23:13:46 2017
 *************************************************************************/


#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
using namespace std;

int ret[20];
bool vis[22];

int t;
int R, r;
int prime[22][22];
int sum;
int dbret[19][2000][20];

void do_prime(){

    bool flag = true;
    int ii, jj;
    for(jj = 1; jj < 20; jj++){
        for(ii = 1; ii < 20; ii++){
            flag = true;
            int n = ii+jj;
            if(ii == jj){
                continue;
            }
            for(int i = 2; i * i <= n; i++) {
                if(n % i == 0){
                    flag = false;
                    break;
                }
            }

            if(flag){
                prime[jj][ii] = 1;
                flag = true;
            }
        }
    }
}

void dfs(int index, int pre, int border, int depth){

    if(depth > border){
        return;
    }

    if(depth == border){
        if(prime[index][1]){
            sum++;
            if(border <= 14){
                R++;
                memcpy(dbret[border-1][R], ret, sizeof(ret));
            }else{
                for(int j = 0; j < border; j++){
                    if(j == border-1){
                        printf("%d", ret[j]);
                    }
                    printf("%d ", ret[j]);
                }
                puts("");

            }
        }
        return;
    }

    vis[index] = 0;
    pre = index;

    int i = 2;
    while(i <= border){
        if (vis[i] && prime[pre][i])
        {
            vis[i] = 0;
            ret[r++] = i;
            dfs(i, pre, border, depth+1);
            --r;
            vis[i] = 1;
        }
        i++;
    }
    return;
}

void do_dfs(){
    for(int i = 2; i <= 14; i += 2){
        sum = 0;
        memset(vis, 1, sizeof(vis));
        vis[1] = 0;
        r = 1;
        R = 0;
        ret[0] = 1;
        dfs(1, 1, i, 1);
        dbret[i-1][0][0] = sum;
    }
}

int main(){
    ios::sync_with_stdio(false);
    int ii = 1;
    memset(prime, 0, sizeof(prime));
    do_prime();
    do_dfs();
    t = 0;
    while(scanf("%d", &t) != EOF){
         printf("Case %d:\n", ii);
        if(t <= 14 && t %2  == 0){
           
            for(int i =  1; i <= dbret[t-1][0][0]; i++)
            {
                for(int j = 0; j < t; j++){
                    if(j == t-1){
                printf("%d", dbret[t-1][i][j]);    
            }
            else{
                 printf("%d ", dbret[t-1][i][j]);    
            }
           
            }                 
                  if(i != dbret[t-1][0][0])
                puts("");
            
            }
            puts("");
        }
        else{
            sum = 0;
            memset(vis, 1, sizeof(vis));
            vis[1] = 0;
            r = 1;
            R = 0;
            ret[0] = 1;
            dfs(1, 1, t, 1);
        }
        puts("");
        ii++;
    }
}

