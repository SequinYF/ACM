//#include <bits/stdc++.h>
#include <iostream>
using namespace std;
int s, n;
int w[1001];
int k[1001];
int ww;
int kk;
int happy;

void func(int i){
    if(i >= n){
        if(kk > happy){
            happy = kk;
        }

        return;
    }

    if(ww + w[i] <= s){
        ww += w[i];
        kk += k[i];
        func(i+1);
        ww -= w[i];
        kk -= k[i];
    }

    func(i+1);
}



int main(){

    ios::sync_with_stdio(false);

    cin >> s >> n;
    for(int i = 0; i < n; i++){
        cin >> w[i] >> k[i];
    }

    func(0);
    cout << happy << endl;
}
