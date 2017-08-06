/********************************************************************
* File Name: taolimigong.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 日  8/ 6 15:17:38 2017
*************************************************************************/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
#include <stdlib.h>
#include <string.h>
using namespace std;
int dir[4][2] = {-1, 0, 0, -1, 1, 0, 0, 1};// \<^>
int vis[105][105];
string maze[105];
int max_turn;
int m, n;
int endx, endy;
const int INF = 1000000; //fuck ll不要赋值int型
bool flag;

void dfs(int x, int y, int d){
    
    if(vis[x][y] > max_turn|| flag) return;
    if(vis[x][y] == max_turn && x != endx && y != endy)  return; //jianzhi
    if(x == endx && y == endy){
            flag = true;
            return;
    }
    maze[x][y] = '*';
    int xx = x;
    int yy = y;
    for(int i = 0; i <= 3; i++){
        xx = x + dir[i][0];
        yy = y + dir[i][1];
        if(xx >= 0 && yy >= 0 && xx < m && yy < n && vis[xx][yy] >= vis[x][y] && maze[xx][yy] != '*'){
            vis[xx][yy] = vis[x][y];
            if(i != d && d != -1){
                vis[xx][yy]++;
            }      
               dfs(xx, yy, i);
               if(flag) return;
        }
    } 
    maze[x][y] = '.';   

}

int main(){
   // freopen("./aa.txt", "w", stdout);
    int T;
    cin >> T;
    while(T--){
         memset(vis, INF, sizeof(vis));
        cin >> m >> n;
        for(int i = 0; i < m; i++){
            cin >> maze[i];
        }
        int x, y;
        cin >> max_turn >> y >> x >> endy >> endx;
        flag = false; 
        endx--;
        endy--;
        x--,y--;
        vis[x][y] = 0;
        dfs(x, y, -1);
        if(flag){
            cout << "yes" << endl;
        } 
        else{
            cout << "no" << endl;
        }    
    }
    return 0;
}
