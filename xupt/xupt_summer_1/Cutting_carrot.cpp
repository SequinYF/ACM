#include <iostream>
#include <algorithm>
#include <cmath>
#include <stdio.h>
using namespace std;

int main(){
    double n, h;
    double hh;
    cin >> n >> h;
    for(double i = 1; i < n; i++){
        hh = h * sqrt(i)/sqrt(n);
        printf("%.12f%c", hh, i==n-1?'\n':' ');
    }
}
