/********************************************************************
* File Name: b.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 五  9/ 1 22:00:20 2017
*************************************************************************/

#include <iostream>
using namespace std;

int a[100007];
int main() {
    int n;
    cin >> n;
    int m, b;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    m = a[0];
    b = a[n-1];

    if(m&1 && b&1) {
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
}
