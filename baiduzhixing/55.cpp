/********************************************************************
 * File Name: 55.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 六  8/12 14:23:55 2017
 *************************************************************************/
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int CaculateWeekDay(int y,int m,int d){
    int a;
    if(m==1||m==2){
        m += 12;
        y--;
    }
    a = (d+2*m+3*(m+1)/5+y+y/4-y/100+y/400)%7;
    return a;
}

int main(){
    int T;
    cin >> T;
    while(T--) {

        int y,m,d;
        scanf("%d-%d-%d", &y, &m, &d);
        int week = CaculateWeekDay(y, m, d);
        if(m == 2 && d == 29 && ((y%4 == 0 && y%100!=0 )|| y%400 == 0)) {
            int t = y + 1;
            int ret = -1;
            while(1){
                if(t% 400 == 0 || (t%4==0 && t %100 != 0)){
                    ret = CaculateWeekDay(t, m, d);
                }
                if( ret == week)    break;
                t++;
            }
            cout << t  << endl;
            continue;
        }
        int i;
        for (i = 1; y+i < 10000; ++i)
        {
            if(CaculateWeekDay(y+i, m, d) == week) {
                break;
            }
        }

        cout << y+i << endl;
    }
}
