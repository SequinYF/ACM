#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

struct node{
    int num;
    int step;
}st,et;
bool vis[10000];
int x, y;
queue<node> Q;

bool prime(int tt){
    for(int i = 2; i*i <= tt; i++){
        if(tt % i == 0){
            return false;
        }
    }
    return true;
}

int change(int i, node now){
    int temp = now.num;
    int tt;
    if(i == 0){
        for(int p = 1; p <= 9; p++){
            tt = p*1000 + temp%1000;
            if(prime(tt) && !vis[tt] && tt != temp){
                vis[tt] = true;
                node next;
                next.num = tt;
                next.step = now.step+1;
                Q.push(next);
            }
        }
    }
    else{
        for(int p = 0; p <= 9; p++){
            if(i == 1){
                tt = temp/1000*1000 + p*100 + temp%100;
                if(prime(tt) && !vis[tt] && tt != temp){
                    vis[tt] = true;
                    node next;
                    next.num = tt;
                    next.step = now.step+1;
                    Q.push(next);
                }
            }
            else if(i == 2){
                tt = temp/100*100 + p*10 + temp%10;
                if(prime(tt) && !vis[tt] && tt != temp){
                    vis[tt] = true;
                    node next;
                    next.num = tt;
                    next.step = now.step+1;
                    Q.push(next);
                }
            }
            else if(i == 3){
                tt = temp/10*10 + p;
                if(prime(tt) && !vis[tt] && tt != temp){
                    vis[tt] = true;
                    node next;
                    next.num = tt;
                    next.step = now.step+1;
                    Q.push(next);
                }
            }
        }
    }
}


void bfs(){
    while(!Q.empty()){
        Q.pop();
    }

    Q.push(st);
    vis[x] = true;
    while(!Q.empty()){
        node temp = Q.front();
        Q.pop();
        if(temp.num == y){
            cout << temp.step<< endl;
            return;
        }
        for(int i = 0; i < 4; i++){
            change(i, temp);
        }
    }
   cout << "Impossible" << endl;
    return;
}

int main(){
    ios::sync_with_stdio(false);
    freopen("ftest.txt", "r", stdin);

    int n;
    cin >> n;
    while(n--){
        cin >> x >> y;
        st.num = x;
        st.step = 0;
        et.num = y;
        et.step = 0;
         memset(vis, false, sizeof(vis));
        bfs();
    }
}
