#include <iostream>
using namespace std;

int p[100005];

int main(){
    int n, k;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> p[i];
    }

    int sum = 0;

    for(int i = 0; i < n; i++){
        if(p[i] % k){
            sum = sum + p[i]/k + 1;
        }
        else{
            sum = p[i]/k + sum;
        }
    }

    sum += 1;
    sum /= 2;
    cout << sum << endl;
}
