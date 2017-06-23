#include <iostream>
using namespace std;
int n, c;
int w[51];
int cc;
int bestc;

void func(int i){
    if(i >= n){
        if(cc > bestc){
            bestc = cc;
        }

        return;
    }

    if(cc + w[i] <= c){
        cc += w[i];
        func(i+1);
        cc -= w[i];
    }

    func(i+1);
}

int main(){
    cin >> n >> c;
    for(int i = 0; i < n; i++){
        cin >> w[i];
    }

    func(0);
    cout << bestc << endl;
    return 0;
}
