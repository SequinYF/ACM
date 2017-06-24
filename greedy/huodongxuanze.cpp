#include <iostream>
#include <queue>
#include <cmath>
#include <algorithm>
using namespace std;
int n;
struct node{
    int s;
    int e;
    int num;
};
int ret;
node act[1001];
queue <int> step;

bool cmp(node a, node b){
    return a.e < b.e;
}

void func(){
    int s = 0;
    step.push(act[s].num);
    ret = (1 + act[0].e-act[0].s);
    for(int i = 1; i < n; i++){
        if(act[i].s >= act[s].e){
            ret += (1 + act[i].e-act[i].s);
            s = i;
            step.push(act[s].num);
        }
    }
}


int main(){

    freopen("huodongxuanze.txt", "r", stdin);

    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> act[i].s >> act[i].e;
        act[i].num = i + 1;
    }

    sort(act, act+n, cmp);

    func();
    cout << ret << endl;
    while(!step.empty()){
        cout << step.front();
        step.pop();
    }
}

