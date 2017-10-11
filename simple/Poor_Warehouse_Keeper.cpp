/********************************************************************
* File Name: Poor_Warehouse_Keeper.cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 二 10/10 20:05:54 2017
*************************************************************************/

#include <iostream>
#include <stdio.h>
#include <cmath>
#include <algorithm>
using namespace std;
int main(){
    double X, Y;
    while(scanf("%lf%lf", &X, &Y) != EOF) {
        double maxcost = Y / X;
        double x = 1, y = 1;
        double cost = 1.0;
        int step = 1;
        while(floor(x) - floor(X) < 10e-2 || floor(y) - floor(Y) < 10e-2) {
            double temp = y + 1;
            if(floor(temp) == Y && floor(x) == X){
                break;
            }
            cout << cost << endl;
            if(maxcost -temp/x < 10e-9){
                cout << maxcost << endl;
                cout << floor(temp)/x << endl;
                cout << temp <<"d" <<x << endl;
                y += cost;
                x += 1;
            }
            else{
                y = temp;
                cost = y / x;
            }
            cout << x << ":"<< y << endl;
            step++;
        }

        cout << step << endl;
    }
}

