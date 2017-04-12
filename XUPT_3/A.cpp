#include <iostream>
#include <vector>
#include <cstdio>
#define NUM  100000
#define LONG 10000000
using namespace std;

typedef struct node{
    int bian[6];
}snow[NUM];

vector<node>hs[NUM];

void hash_(node tt){
    int no = 0;
    for(int i = 0; i < 6; i++){
        no += tt.bian[i];
    }
    no %= NUM;
    hs[no].push_back(tt);
}

bool cmp(node s1, node s2){

}

int main(){
    ios::sync_with_stdio(false);
    int n;
    node tt;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            scanf("%d", &tt.bian[j]);
        }
        hash_(tt);
    }

    for(int i = 0; i < NUM; i++){
        if(hs[i].size() <= 1){
            continue;
        }

        for(int j = 0; j < hs[i].size(); j++){
            for(int k = j + 1; k < hs[i].size(); k++){
                if(cmp(hs[i][j], hs[i][k])){
                    printf("Twin snowflakes found.\n");
                }
            }
        }
    }

    printf("No two snowflakes are alike.\n");

}
