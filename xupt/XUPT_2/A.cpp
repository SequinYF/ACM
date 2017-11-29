#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;
int num[150][150];
int dist[150][150];
int N;

int dp(int i, int j){
    if(dist[i][j] >= 0){
        return dist[i][j];
    }

    return dist[i][j] = num[i][j] + (i == N ? \
             0 : max(dp(i+1, j), dp(i+1, j+1)));
}


int main(){
    freopen("atest.txt", "r", stdin);
    int n;
    cin >> n;
    while(n--){
        cin >> N;
        memset(num, 0, sizeof(num));
        for(int i = 1; i <= N; i++){
            for(int j = 1; j <= i; j++){
                cin >> num[i][j];
            }
        }
    }
    memset(dist, -1, sizeof(dist));
    cout << dp(0, 0) << endl;
}
