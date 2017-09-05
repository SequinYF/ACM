/********************************************************************
* File Name: X_Plosices.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 二  9/ 5 22:10:16 2017
*************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;

int p[100006];

int find(int x) {
    return p[x] == x ? x : p[x] = find(p[x]);
}


int main() {
    int a, b;
    while(cin >> a && a != -1) {
        for(int i = 0; i <= 100000; i++) {
            p[i] = i;
        }
        int ret = 0;
        while(a != -1) {
            cin >> b;
            int pa = find(a);
            int pb = find(b);

            if(pa == pb) ret++;
            else{
                p[pa] = pb;
            }
            cin >> a;
        }

        cout << ret << endl;
    }
}
