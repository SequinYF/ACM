#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    long long n, k;
    long long a[100005];
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    sort(a, a+n);
    for(int i = n-1; i > 0; i--){
        long long t = a[i] - a[i-1];
        t %= k;
        if(t){
            cout << -1 << endl;
            return 0;
        }
    }

    long long sum = 0;
    for(int i = 0; i < n; i++){
        long long t = a[i] - a[0];
        sum += (t/k);
    }

    cout << sum << endl;
}
