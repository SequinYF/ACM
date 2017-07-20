#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int aa;
    cin >> aa;
    int count = 0;
    for(int i = 1; i < n; i++){
        int temp;
        cin >> temp;
        if(temp <= aa){
            count++;
        }
    }
    count /= count;
    count++;
    cout << count << endl;
}
