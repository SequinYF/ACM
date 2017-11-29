#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

int n;
long long a[200005];
long long f1[200005];
long long f2[200005];

long long dp(long long f[]){

    long long mmax = 0;
    long long sum = 0;
    for(int i = 0; i < n - 1; i++){
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
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    a[n] = 0;
    for(int i = 0; i < n; i++){
        f1[i] = abs(a[i] - a[i+1]);
        if(i & 1){
            f1[i] = -f1[i];
        }
        f2[i] = -f1[i];
    }

    long long r1 = dp(f1);
    long long r2 = dp(f2);

    long long ret = max(r1, r2);

    cout << ret << endl;
}
