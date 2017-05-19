#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>
#include <cmath>
#include <algorithm>
using namespace std;

typedef struct node{
    int s, e;
}node;

bool cmp(node a, node b){
    return a.e < b.e;
}

int main(){

    freopen("k.txt", "r", stdin);

    int n;
    while(cin >> n && n){
        int count = 1;
        node tv[n+1];
        for(int i = 0; i < n; i++){
            int &s = tv[i].s;
            int &e = tv[i].e;
            cin >> s >> e;
        }

        sort(tv, tv+n, cmp);

        int min = tv[0].e;

        for(int i = 1; i < n; i++){
            int s = tv[i].s;
            if(s >= min){
                count++;
                min = tv[i].e;
            }
        }

        cout << count << endl;
    }
}
