#include <iostream>
#include <cstdio>
#include <string.h>
#include <queue>
using namespace std;
char map[35][35][35];
bool vis[35][35][35];
int L, R, C;
int ex, ey, ez;
int dx[6] = {0, 0, -1, 1, 0, 0};
int dy[6] = {0, 0, 0, 0, 1, -1};
int dz[6] = {1, -1, 0, 0, 0, 0};

struct Node{
    int x, y, z;
    int time;
}start;

queue <Node> Q;

bool check(int x, int y, int z){ //边界判断
    if(x >= 0 && y >= 0 && z >= 0 && x < L && y < R && z < C){
        return true;
    }
    return false;
}



int bfs(){
    while(!Q.empty()){
        Node now = Q.front();
        Q.pop();
        Node next;
        for(int i = 0; i < 6; i++){
            next.x = now.x + dx[i];
            next.y = now.y + dy[i];
            next.z = now.z + dz[i];
            if(check(next.x, next.y, next.z) && map[next.x][next.y][next.z] != '#' && vis[next.x][next.y][next.z] == false){
                if(next.x == ex && next.y == ey && next.z == ez){
                    return now.time+1;
                }
                next.time = now.time +1;
                vis[next.x][next.y][next.z] = true;
                Q.push(next);
            }
        }

    }
    return -1;
}



int main(){
    ios::sync_with_stdio(false);
    freopen("btest.txt", "r", stdin);

    while(cin >> L >> R >> C && R+L+C){
        memset(vis, 0, sizeof(vis));
        for(int i = 0; i < L; i++){
            for(int j = 0; j < R; j++){
                for(int k = 0; k < C; k++){
                    char &tt = map[i][j][k];
                    cin >> tt;
                    if(tt == 'S'){
                        start.x = i;
                        start.y = j;
                        start.z = k;
                        start.time = 0;
                        Q.push(start);
                        vis[i][j][k] = true; //
                    }
                    else if(tt == 'E'){
                        ex = i;
                        ey = j;
                        ez = k;
                    }
                }
            }
        }

        int ret = bfs();
        if(ret == -1){
            cout << "Trapped!" << endl;
        }
        else{
            cout << "Escaped in " << ret << " minute(s)." << endl;
        }

        while(!Q.empty()){
            Q.pop();
        }
    }
    return 0;
}
