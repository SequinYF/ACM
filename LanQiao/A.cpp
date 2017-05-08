#include <iostream>
#include <string.h>
using namespace std;

int vis[10][10];
int mmap[10][10];
int count = 0;

int find_(int i, int j){
    int a = i, b = j;
    while(1){

        switch(mmap[i][j]){
            case 'U': j--;break;
            case 'L': i--;break;
            case 'R': i++;break;
            case 'D': j++;break;
        }

        if(i < 0 || i > 9 || j < 0 || j > 9 ){
            count++;
            break;
        }
        if(a == i && b == j){
            break;
        }
    }

    return 0;
}


int main(){
    freopen("A.txt", "r", stdin);

    for(int i = 0; i <10; i++){
        for(int j = 0; j < 10; j++){
            cin >> mmap[i][j];
        }
    }

    for(int i = 0; i <= 10; i++){
        for(int j = 0; j <= 10; j++){
            memset(vis, 0, sizeof(vis));
            find_(i, j);
        }
    }

    cout << count << endl;
}

