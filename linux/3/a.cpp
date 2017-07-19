#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int n;
    int f[56] = {1, 1, 2, 3};
    for(int i = 4; i <= 55; i++){
        f[i] = f[i-1] + f[i-3];
    }

    while(cin >> n && n){
        cout << f[n] << endl;
    }
}
