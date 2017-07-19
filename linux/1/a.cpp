#include <iostream>
#include <algorithm>
using namespace std;

bool s_f;
int s_i;
bool s_d;

int main(){
    string s;
    while(cin >> s)
    {
        s_f = s_d = false;
        s_i = -1;
        int len = s.length() - 1;
        for(int i = 0; i <= len; i++){
            if(s[0] == '.' || s[0] == '@' || s[len] == '.' || s[len] == '@'){
                cout << "NO" << endl;
                s_d = true;
                break;
            }
            if(s[i] == '@'){
                s_i = i;
                s_f =true;
                continue;
            }

            if(s_f){
                if(s[i] == '@'){
                    cout << "NO" << endl;
                    break;
                }
                if(s[i] == '.'){
                    s_d = true;
                    if(i == s_i + 1){
                        cout << "NO" << endl;
                    }
                    else
                        cout << "YES" << endl;
                    break;
                }
            }
        }
        if(!s_d){
                        cout << "NO" << endl;
        }

    }
}
