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

int main(){
    double X, Y;
    while(scanf("%lf%lf", &X, &Y) != EOF) {
        double per = 1.0;
        double x = 1.0, y = 1.0;
        int step = 0;
        if(X == 1 && Y == 1) {
            printf("%d\n", 1);
            continue;
        }
        while(floor(x) != X && floor(y) != Y) {
            if(per - Y/(X*1.0) > 10e-9) {
                step--;
                per = (y-1)/x;
                y += (per-1);
                printf("%f %f\n", per, y);
                x += 1.0;
            }
            else
                y += 1;
            per = y / (x * 1.0);
            printf("%f\n", per);
            printf("%f %f\n", x, y);
            step++;
        }

        printf("%d\n", step-1);
    }
}

