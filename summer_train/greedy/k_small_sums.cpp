/********************************************************************
* File Name: k_small_sums.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 二  9/ 5 20:58:52 2017
*************************************************************************/
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;


int arr[1000][1000];

struct node{
    int b;
    int s;
    node(int s, int b):s(s), b(b) {  }
    bool operator < (const node& a) const {
        return a.s < s;
    }
};


void merge(int a[], int b[], int c[], int n) {
    priority_queue <node> pq;

    for(int i = 0; i < n; i++) {
        pq.push(node(a[i]+b[0], 0));
    }

    for(int i = 0; i < n; i++) {
        node tmp = pq.top();
        pq.pop();
        c[i] = tmp.s;
        int nowb = tmp.b + 1;
        int nows = tmp.s - b[tmp.b] + b[tmp.b + 1];
        pq.push(node(nows, nowb));
    }
}

int main() {
    int n;
    while(cin >> n) {
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                cin >> arr[i][j];
            }
            sort(arr[i], arr[i]+n);
        }

        for(int i = 1; i < n; i++) {
            merge(arr[0], arr[i], arr[0], n);
        }

        cout << arr[0][0];
        for(int i = 1; i < n; i++) {
            cout << " " << arr[0][i];
        }
        cout << endl;
    }
}
