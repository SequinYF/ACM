#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
int m, n;
char mmap[101][101];
bool vis[101][101];
int count;
int dir[8][2] = {1, 1, -1, 1, 1, 0, 1, -1, 0, -1, -1, -1, -1, 0, 0, 1};

bool check(int xx, int yy){
    if(xx >= 0 && xx < m && yy >= 0 \
             && yy < n && mmap[xx][yy] == '@' && vis[xx][yy]){
        return true;
    }

    return false;
}


void dfs(int x, int y){
   // if(vis[x][y]){
    //     return;
   // }

    for(int i = 0; i < 8; i++){
        int xx = x + dir[i][0];
        int yy = y + dir[i][1];
        if(check(xx, yy)){
            vis[xx][yy] = false;
            dfs(xx, yy);
        }
    }

    return;
}


int main(){

    freopen("A.txt", "r", stdin);

    while(cin >> m >> n && m + n){

        memset(vis, 1, sizeof(vis));
        memset(mmap, 0, sizeof(mmap));
        count = 0;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                cin >> mmap[i][j];
            }
        }

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(vis[i][j] && mmap[i][j] == '@'){
                    vis[i][j] = false;
                    dfs(i, j);
                    count++;
                }
            }
        }
        cout << count << endl;
    }
}
