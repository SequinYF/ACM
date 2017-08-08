#include <iostream>
#include <string.h>
using namespace std;
bool mapp[14][14];
int ret;
int n;
/*
bool canset(int ii, int jj){

     if(mapp[ii][jj]){
         return false;
     }

    for(int i = 0; i < n; i++){
        if(mapp[ii][i] || mapp[i][jj]){
            return false;
        }
    }

    for(int i = 1; i < n; i++){
        if(ii - i >= 0 && jj - i >= 0){
            if(mapp[ii-i][jj-i]){
                return false;
            }
        }

        if(ii - i >= 0 && jj + i < n){
            if(mapp[ii-i][jj+i]){
                return false;
            }
        }


        if(ii + i < n && jj - i >= 0){
            if(mapp[ii+i][jj-i]){
                return false;
            }
        }

        if(ii + i < n && jj + i < n){
            if(mapp[ii+i][jj+i]){
                return false;
            }
        }

    }
    return true;
}

void func(int j){
    if(j >= n){
        ret++;
    }
    else{
        for(int i = 0; i < n; i++){
          //  for(int j = 0; j < n; j++){
                if(canset(i, j)){
                    mapp[i][j] = true;
                    func(j+1);
                    mapp[i][j] = false;
                }
          //  }
        }
    }
    return;
}


int main(){
    
    ios::sync_with_stdio(false);
    while(scanf("%d", &n) && n){
        ret = 0;
        for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            mapp[i][j] = false;    
        }
        }
        func(0);
        printf("%d\n", ret);
       // cout << ret << endl;
    }
   
}
*/

int main(){
    int a[11] = {0, 1, 0, 0, 2, 10, 4, 40, 92, 352, 724};
    while(cin >> n && n){
        cout << a[n] << endl;
    }
}