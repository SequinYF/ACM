#include <iostream>
#include <cstdlib>
using namespace std;

/*
long long unsigned dfs(long long unsigned n, long long unsigned num, int d){
    if(n >= num){
        return 0;
    }

    if(num%d == 0){
        cout << num << endl;
        return 1;
    }
    if(dfs(num, num*10, d)){
        return 1;
    }

    return dfs(num, num*10+1, d);

}


int main(){
    int d;
    while(cin >> d && d){
        dfs(0, 1, d);
    }
}

*/

int mod[524286];

int main(){
    int n, i;
    while(cin >> n && n){
        mod[1] = 1;

        for(i = 2; mod[i-1] != 0; i++){
            mod[i] = (mod[i/2]*10 + i%2)%n;
        }

        i--;

        int p = 0;
        while(i){
            mod[p++] = i%2;
            i /= 2;
        }

        while(p){
            cout << mod[--p];
        }
        cout << endl;
    }
}
