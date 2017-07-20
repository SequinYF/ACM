#include <iostream>
#include <algorithm>
using namespace std;

int num[101], n;
void qs(int left, int right){
    int i, j;
    i = left;
    j = right;
    if(i > j){
        return;
    }

    int index = num[i];
    while(i != j){
        while(num[j] >= index && i < j){
            j--;
        }
        while(num[i] <= index && i < j){
            i++;
        }
        if(i < j){
            swap(num[i], num[j]);
        }
    }

    swap(num[left], num[i]);

    qs(left, j-1);
    qs(i+1, right);
}





int main(){
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> num[i];
    }

    qs(1, n);

    for(int i = 1; i <= n; i++){
        cout << num[i];
    }
}
