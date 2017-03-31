#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
bool vis[100002];
int N, K, step;
int dir[2] = {1, -1};
int path[100002];
queue <int> Q;

void bfs(){
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        for(int i = 0; i < 3; i++){ //将走的方式看作是一种方向，那么题目就可以转变为BFS
            int tt;
            if(i == 2){
                tt = now * 2;
            }
            else{
                tt = now + dir[i];
            }
            if(tt > 0 && tt < 100001 && !vis[tt]){  //判断方式很简单，只要是在图的范围内并且没有访问过就可以了
                if(tt == K){
                    cout << path[now]+1 << endl;
                    return;
                }
                vis[tt] = true;
                path[tt] = path[now] + 1; //这里用来记录步数,走到第i个点用论文path[i]步，那么从i到下一个点就用了path[i]+1步
                Q.push(tt);
            }
        }
    }
}


int main(){
    ios::sync_with_stdio(false);
    memset(path, 0, sizeof(path));
    memset(vis, false, sizeof(vis));

    cin >> N >> K;
    if(N >= K){ //当cow的位置比john小时候，john只有向后退才会离cow越来越近，只有-1的方式能用，所以直接相减就行了。
        cout << N - K << endl;
    }
    else{
        Q.push(N);
        vis[N] = true;
        bfs();
    }
}
