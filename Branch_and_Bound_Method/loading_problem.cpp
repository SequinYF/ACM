#include <iostream>
#include <queue>
using namespace std;

template <class Type> Type loading(Type w[], Type c, int n){
    queue <Type> Q;
    int wt;
    int i = 1;
    int bestw;
    int ew = 0;

    Q.push(-1);

    for(int j = 2; j <= n; j++){
        r += w[j];
    }

    while(true){
        wt = ew + w[i];
        if(wt <= c){
            if(wt > bestw){
                bestw = wt;
            }

            if(i < n){    //非叶子节点，这个很重要，不要忘
                Q.push(wt);
            }
        }

        if(ew + r > bestw && i < n){
            Q.push(ew);
        }

        ew = Q.front();
        Q.pop();

        if(ew == -1){
            if(Q.empty()){
                return bestw;
            }
            ew = Q.front();
            Q.pop();
            Q.push(-1);
            i++;
            r -= w[i];
        }
    }
}
