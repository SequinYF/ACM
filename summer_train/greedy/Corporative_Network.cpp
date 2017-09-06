/********************************************************************
* File Name: Corporative_Network.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 三  9/ 6 16:24:07 2017
*************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#define maxn 30000
int p[maxn];
int dis[maxn];

int find(int x) {
    if(x == p[x])    return x;
    else{
        int root = find(p[x]);
        dis[x] += dis[p[x]];
        p[x] = root;
        return root;
    }
}

int main() {
    int n;
    cin >> n;
    while(n--) {

        int N;
        cin >> N;
        for(int i = 1; i <= N; i++) {
            dis[i] = 0;
            p[i] = i;
        }

        char t;
        while(cin >> t && t != 'O'){
            if(t == 'E') {
                int x;
                cin >> x;
                find(x);
                cout << dis[x] << endl;
            }

            if(t == 'I') {
                int a, b;
                cin >> a >> b;
                p[a] = b;
                dis[a] = abs(b - a) % 1000;
            }
        }
    }
}

