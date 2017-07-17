#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
int a[100005];
int f1[100005];
int f2[100005];

int dp(int f[]){

    int mmax = f[1];
    int sum = 0;
    for(int i = 1; i < n; i++){
        sum += f[i];
        if(sum < 0){
            sum = 0;
        }
        mmax = max(mmax, sum);
    }

    return mmax;

}



int main(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    for(int i = 1; i < n; i++){
        f1[i] = abs(a[i] - a[i+1]);
        if(i & 1){
            f1[i] = -f1[i];
        }
        f2[i] = -f1[i];
    }


    int ret = max(dp(f1), dp(f2));

    cout << ret << endl;
}


