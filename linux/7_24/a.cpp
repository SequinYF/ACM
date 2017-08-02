#include <iostream>
#include <map>
using namespace std;

int main(){
    map<char, int> m;
    char ch;
    int mmin = 1000000;
    string s;
    bool flag;
    cin >> s;
    m['B'] = m['b'] = m['u']=m['l']= m['a']=m['s']=m['r'] = 0;
    for(int i = 0; i < s.length(); i++){
        ch = s[i];
        m[ch]++;

    }
    map<char, int>::iterator itr;
    for(itr = m.begin(); itr != m.end(); ++itr){
        ch = itr->first;
        if(ch == 'B' || ch == 'u' || ch == 'l' || ch == 'b' || ch == 'a' || ch == 's' || ch == 'r')
        {
            flag = true;
            if(itr->first == 'a' || itr->first == 'u'){
                itr->second += 1;
                itr->second /= 2;
            }
            if(itr->second < mmin){
                mmin = itr->second;
            }
        }
    }
    if(!flag)
        mmin = 0;

    cout << mmin << endl;
}
