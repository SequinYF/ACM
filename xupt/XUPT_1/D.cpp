#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
int M, N, ret;
int map[20][20];
int copy_[20][20];
int path[20][20];
int dir[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
bool try_(int way);

void change(int i, int j){
    ret++; //当前方式的步数
    path[i][j] += 1;
    copy_[i][j] ^= 1; //按下点取反
    for(int d = 0; d < 4; d++){
        int ii = i + dir[d][0];
        int jj = j + dir[d][1];
        if(ii >= 0 && jj >= 0 && ii < M && jj < N){
            copy_[ii][jj] ^= 1;
        }
    }
}

bool try_(int way){

    memcpy(copy_, map, sizeof(map)); //初始化复制的map
    ret = 0; //初始化步数，不要总是WA在初始化上

    for(int j = 0; j < N; j++){  //当前第一行的翻转方式为way变成二进制的值，按位与将有1的翻转
        if(way & (1 << (N-j-1))){
            change(0, j);
        }
    }

    for(int i = 1; i < M; i++){ //由way得到的翻转方式，进行处理，处理第一行要从第二处理
        for(int j = 0; j < N; j++){  //就不会影响到上一行的翻转了
            if(copy_[i-1][j] == 1){ //如果上一行的某列为1， 那么处理此行的此列
                change(i, j);
            }
        }
    }

    for(int j = 0; j < N; j++){ //由于对一直对上一行判断处理会剩下最后一行无法处理
        if(copy_[M-1][j]){  //判断最后一行是否有1，如果有则说明翻转第一行的way方法不能得到
            return false; //全部翻转为零的情况
        }
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);
    freopen("dtest.txt", "r", stdin);

    cin >> M >> N;
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
        }
    }

    int min = N*M + 1; //min为最小步数的判断
    int step = -1; //最小步数时的起点翻转

    for(int i = 0; i < (1 << N); i++){ //对于第一行来说，要翻转总共有2^N种，0～2^N-1.枚举所有的方式
        if(try_(i) && ret < min){ //如果可以全部为0并且是目前的最小步数
            min = ret;
            step = i;
        }
    }

    memset(path, 0, sizeof(path)); //之前会给path赋值
    if(step >= 0){
        try_(step); //重新来得到路径
        for(int i = 0; i < M; i++){
            for(int j = 0; j < N; j++){
                cout << path[i][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        cout << "IMPOSSIBLE" << endl;
    }
}
