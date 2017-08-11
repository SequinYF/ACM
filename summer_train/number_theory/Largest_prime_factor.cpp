/********************************************************************
 * File Name: Largest_prime_factor.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 五  8/11 19:38:36 2017
 *************************************************************************/
#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;
#define MAX 1000000

int num[MAX];

int main(){
	ios::sync_with_stdio(false);
    memset(num, 0, sizeof(num));
    int index = 1;
    for(int i = 2; i < MAX; i++) {
        if(!num[i]) {
            num[i] = index;
            for(int j = 2*i; j < MAX; j += i) {
                num[j] = index;
            }
            index++;
        }

    }
    int n;
    while(cin >> n) {
        cout << num[n] << endl;
    }
    return 0;
}
