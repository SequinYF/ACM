#include <cstdio>
#include <iostream>
#include <string>
#include <string.h>
#include <cstdlib>
using namespace std;
char map[8][8]; //图
int col[8]; //列数，记录可以放的列
int chess, count; // chess 当前已放置棋子数目， count 棋子放置方法数
int n, k;

void dfs(int row){

    if(chess == k){ //已经放了k个棋子，说明所有的棋子都已经放好了
        count++; //方式+1
        return;
    }
    if(row >= n){ //超出边界
        return;
    }

    for(int i = 0; i < n; i++){
        if(map[row][i] == '#' && col[i] == 0){ //如果当前row行i列为棋盘区域并且第i列可以放置
            col[i] = 1; //更改列状态
            chess++; //处理下一个棋子
            dfs(row + 1); //搜索下一行
            col[i] = 0; //搜索返回列状态清空
            chess--; //搜索返回开始处理当前棋子
        }
    }
    dfs(row + 1);//此行不能放置，开始下一行
}



int main(){

    freopen("atest.txt", "r", stdin);
    ios::sync_with_stdio(false);

    while(cin >> n >> k && n != -1 && k != -1){
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> map[i][j];
            }
        }
        for(int i = 0; i < n; i++){
            col[i] = 0;
        }
        chess = 0;
        count = 0;
        dfs(0);
        cout << count << endl;
    }
}
