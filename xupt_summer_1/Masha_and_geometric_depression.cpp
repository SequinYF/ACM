#include <iostream>
#include <map>
#include <algorithm>
using namespace std;
int b1, q, l, m;
int b1f = false;
int qf = false;
map <long long, bool> a;

int main(){
    int aa;

    ios::sync_with_stdio(false);

    cin >> b1 >> q >> l >> m;
    for(int i = 0; i < m; i++){
        cin >> aa;
        if(aa == b1){
            b1f  = true;
        }
        if(aa == 0){
            qf = true;
        }

        a[aa] = true;
    }

    if(q == 0){
        if(b1 > l){
            cout << 0 << endl;
        }
        else if(qf){
            if(b1f)

                cout << 0 << endl;
            else
                cout << 1 << endl;
        }
        else {
            cout << "inf" << endl;
        }

    }
    else if(b1 == 0){
        if(b1f){

            cout << 0 << endl;
        }
        else{
            cout << "inf" << endl;
        }
    }
    else if(q == 1){
        if(l < b1)
            cout << 0 << endl;
        else{
            if(b1f){
                cout << 0 << endl;
            }
            else{
                cout << "inf" << endl;
            }
        }
    }
    else if(q == -1){
        if(b1f && qf){
            cout << 0 << endl;
        }
        else{
            cout << "inf" << endl;
        }
    }
    else{
        int bn = b1;
        int j = 0;
        int i = 0;
        while(bn <= l){
            if(!a[bn]){
                i++;
            }
            bn = bn * q;
        }
        cout << i << endl;
    }


}
