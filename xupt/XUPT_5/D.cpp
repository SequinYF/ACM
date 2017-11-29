#include <cstdio>
#include <iostream>
#include <string.h>
using namespace std;
#define NUM 10001
#define INF 0x3fffffff
int go_map[NUM][NUM];
int back_map[NUM][NUM];
bool vis[NUM];
int N, M, X;
int d[NUM];

int dijk(int map[][NUM]){
    vis[X] = true;
    for(int i = 1; i <= N; i++){
        d[i] = map[X][i];
    }

    int j;

    for(int i = 1; i < N; i++){
        int mmin, m = INF;
        for(j = 1; j <= N; j++){
            if(!vis[j] && d[j] < m){
                m = d[j];
                mmin = j;
            }
        }

        vis[mmin] = true;

        for(int k = 1; k <= N; k++){
            d[j] = min(d[j], d[mmin] + map[mmin][j]);
        }
    }

    int ret = INF;
    for(int i = 1; i <= N; i++){
        cout << d[i] << endl;
        if(d[i]){
        ret = min(ret, d[i]);

        }
    }

    return ret;
}




int main(){

    freopen("dtest.txt", "r", stdin);

    cin >> N >> M >> X;

    for(int i = 1; i <= N; i++){
        go_map[i][i] = back_map[i][i] = 0;
        for(int j = 1; j < i; j++){
            go_map[i][j] = INF;
            back_map[i][j] = INF;
        }
    }
    for(int i = 1;  i <= M; i++){
        int a, b, c;
        cin >> a >> b >> c;
        go_map[a][b] = c;
        back_map[b][a] = c;
    }

    memset(vis, false, sizeof(vis));
    int ret;
    ret = dijk(go_map);
    cout << ret << endl;
}
