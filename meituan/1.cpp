#include <iostream>
#include <cmath>
using namespace std;
int main(){
    int a[1001];
    int b[1001];
    int aa, bb;
    long long mmin = 2e9;
    int sum = 0;
    cin >> aa;
    for(int i = 1; i <= aa; i++){
        cin >> a[i];
    }
    cin >> bb;
    for(int i = 1; i <= bb; i++){
        cin >> b[i];
    }

    int c[1001];
    int j;

    for(int i = 1; i <= bb - aa+1; i++){
        sum = 0;
        for(j = 1; j <= aa; j++){
            c[j] = a[j] - b[i+j-1];
            c[j] *= c[j];
        }
        j--;
        while(j > 0){
            sum += c[j];
            j--;
        }

        if(mmin > sum){
            mmin = sum;
        }
    }
    cout << mmin << endl;


    return 0;
}
