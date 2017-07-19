#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


int func(int a, int b){
    int c;

    while(b){
        c = a % b;
        a = b;
        b = c;
    }

    return a;
}

int main(){
    int n;
    int num;
    while(cin >> n){
        int ret = 1;
        for(int i = 0; i < n; i++){
            cin >> num;
            long r = func(ret, num);
            ret = ret/r *num;
        }

        cout << ret << endl;
    }
}
