/********************************************************************
 * File Name: fang_fang.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 三  9/ 6 21:59:37 2017
 *************************************************************************/

#include <iostream>
#include <string.h>
#define maxn 1000009
using namespace std;

char f[maxn];
int main() {
    int n;
    cin >> n;
    getchar();

    for(int t = 1; t <= n; t++) {
        gets(f);
        bool flag = true;
        bool val = true;
        int len = strlen(f);
        int index = 0;
        bool mark = true;
        int fcount = 0;
        int ret;
        for(int i = 0; i < len; i++) {
            f[i+len] = f[i];
            if(f[i] == 'c') {
                index = i;
                flag = false;
                break;
            }
        }

        ret = 0;
        for(int i = index; i < index + len; i++) {
            //cout << f[i] << endl;
            if(f[i] == 'c') {
                if(val != true) {
                    mark = 0;
                    break;
                }
                val = false;
                fcount = 0;
                ret++;
            }
            else if(f[i] == 'f'){
                fcount++;
          //      cout << fcount << endl;
                if(fcount >= 2) {
                    val = true;
                }
            }
            else{
                mark = 0;
            }
        }

        if(!flag && fcount < 2) {
            mark = 0;
        }

        //cout << fcount << endl;
        cout << "Case #" << t << ": ";
        if(mark == 0) {
            cout << "-1" << endl;
        }
        else if(!flag){
            cout << ret << endl;
        }
        else if(flag) {
            if(fcount%2 == 0)
                cout << fcount/2 << endl;
            else
                cout << fcount/2+1 << endl;
        }
    }
}
