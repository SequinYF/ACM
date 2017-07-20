#include <iostream>
using namespace std;
int num[10002];

int main(){
    int n, m;

    while( cin >> n >> m)
    {
        bool flag = false;
        int k = 0;
        for(int a = 1; a <= 9; a++)
            for(int b = 0; b <= 9; b++)
                for(int c = 0; c <= 9; c++){
                    int t = a*100+b*10+c;
                    if(t >= n && t <= m)
                        if(a*100+b*10+c == a*a*a+b*b*b+c*c*c){
                            flag = true;
                            num[k++] = t;
                        }
                }

        if(flag){
            for(int i = 0; i < k-1; i++){
                cout << num[i] << " ";
            }
            cout << num[k-1] << endl;
        }
        else{
            cout << "no" << endl;
        }
    }
}
