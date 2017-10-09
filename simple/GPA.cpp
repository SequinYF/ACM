/********************************************************************
 * File Name: GPA.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 一 10/ 9 19:17:41 2017
 *************************************************************************/
#include <iostream>
#include <string.h>
#include <string>
#include <map>
#include <stdio.h>
using namespace std;

map <string, double> mm;

int main() {

    mm["A"] = 4.0;
    mm["A-"] = 3.7;
    mm["B+"] = 3.3;
    mm["B"] = 3.0;
    mm["B-"] = 2.7;
    mm["C+"] = 2.3;
    mm["C"] = 2.0;
    mm["C-"] = 1.7;
    mm["D"] = 1.3;
    mm["D-"] = 1.0;
    mm["F"] = 0;

    int n;
    while(cin >> n){
        double ret = 0;
        double sum = 0;
        while(n--) {
            int c;
            string s;
            cin >> c;
            cin >> s;
            if(s == "N" || s == "P") {
                continue;
            }
            ret += mm[s] * c;
            sum += c;
        }
        if(sum == 0) {
            cout << "0.00" << endl;
            continue;
        }
        double ans = ret / sum;
        printf("%.2lf\n", ans);
    }
}
