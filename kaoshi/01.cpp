#include <iostream>
#include <algorithm>
using namespace std;

int v[6] = {0, 6, 3, 5, 4, 6};
int w[6] = {0, 2, 2, 6, 5, 4};
int weight = 10;
int d[6][11];

int main(){
    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 10; j++){
            d[i][j] = (i == 1 ? 0 : d[i-1][j]);
            if(j >= w[i]){
                d[i][j] = max(d[i][j], d[i-1][j-w[i]] + v[i]);
            }
        }
    }

    for(int i = 1; i <= 5; i++){
        for(int j = 1; j <= 10; j++){
            cout << d[i][j];
        }
        cout << endl;
    }
}
