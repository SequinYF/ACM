#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <string.h>
using namespace std;

int main(){
    string s;
    stack <char> t;
    char u[100005];

    cin >> s;
    int len = s.length();
    int c = 0;
    char temp;
    for(int i = 0; i < len; i++){
        if(temp <= s[i] || t.empty()){
            t.push(s[i]);
            temp = t.top();
        }
        else{
            char ss = s[i];
            while(temp > ss && !t.empty()){
                u[c++] = temp;
                t.pop();
                if(!t.empty())
                temp = t.top();
            }
            t.push(ss);
            temp = t.top();
        }
    }
    while(!t.empty()){
        u[c++] = t.top();
        t.pop();
    }


    for(int i = len - 1; i  >= 0; i--){
        cout << u[i];
    }
    cout << endl;

}
