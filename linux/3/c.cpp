#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    while(n--){
        string ss;
        cin >> ss;
        int count = 0;
        for(int i = 0; i < ss.length(); i++){
            if(ss[i] < 0){
                count++;
            }
        }
        cout << count/2 << endl;
    }
}
