#include <iostream>
#include <string.h>
using namespace std;
bool mapp[14][14];
int ret;
int n;

bool canset(int ii, int jj){

    if(mapp[ii][jj]){
        return false;
    }

    for(int i = 0; i < n; i++){
        if(mapp[ii][i] || mapp[i][jj]){
            return false;
        }
    }

    for(int i = 0; i < n; i++){
        if(ii - 1 >= 0 && jj - 1 >= 0){
            if(mapp[ii-1][jj-1]){
                return false;
            }
        }

        if(ii - 1 >= 0 && jj + 1 < n){
            if(mapp[ii-1][jj+1]){
                return false;
            }
        }


        if(ii + 1 < n && jj - 1 >= 0){
            if(mapp[ii+1][jj-1]){
                return false;
            }
        }

        if(ii + 1 < n && jj + 1 < n){
            if(mapp[ii+1][jj+1]){
                return false;
            }
        }
    }
    return true;
}

void func(int t){
    if(t >= n){
        ret++;
    }
    else{
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                if(canset(i, j)){
                    mapp[i][j] = true;
                    func(t+1);
                    mapp[i][j] = false;
                }
            }
        }
    }
    return;
}


int main(){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mapp[i][j] = false;
        }
    }
    cin >> n;
    func(0);
    cout << ret << endl;
}
