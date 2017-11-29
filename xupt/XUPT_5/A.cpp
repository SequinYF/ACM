#include <iostream>
#include <string.h>
#include <vector>
#include <iostream>
using namespace std;
#define INF 0x3fffffff
#define MAX 10005

int d[MAX];
int gp[MAX][MAX];
bool vis[MAX];

void dijk(int n){
    memset(&vis, false, sizeof(vis));

    vis[1] = true;

    for(int i = 1; i < n; i++){
        int x, m = INF;
        for(int j = 1; j <= n; j++){
            if(!vis[j] && d[j] < m){
                m = d[j];
                x = j;
            }
        }

        vis[x] = true;

        for(int j = 1; j <= n; j++){
            d[j] = min(d[j], d[x] + gp[x][j]);
        }
    }


    cout << d[n] << endl;
}



int main(){

    freopen("atest.txt", "r", stdin);

    int N, T;
    while(cin >> T >> N){

        for(int i = 1; i <= N; i++){
            gp[i][i] = 0;
            for(int j = 1; j < i; j++){
                gp[i][j] = gp[j][i] = INF;
            }
        }


        for(int i = 1; i <= T; i++){
            int a, b, c;
            cin >> a >> b >> c;
            if(c < gp[a][b])
                gp[a][b] = gp[b][a] = c;
        }

        //	for(int i = 1; i <= N; i++){
        //		for(int j = 1; j <= N; j++){
        //			cout << gp[i][j] << " ";
        //		}
        //		cout << endl;
        //	}

        for(int i = 1; i <= N; i++){
            d[i] = gp[1][i];
        }

        dijk(N);
    }
    return 0;
}
