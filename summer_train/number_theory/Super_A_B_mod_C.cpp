/********************************************************************
 * File Name: Super_A_B_mod_C.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 五  8/11 21:45:55 2017
 *************************************************************************/

#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

#define ll long long

ll getphi(int n) {
    int ans = n;
    for(int i = 2; i * i <= n; i++) {
        if(n % i == 0){
            ans -= ans/i;
            while(n % i == 0) {
                n /= i;
            }
        }
    }
    if(n > 1) {
        ans -= ans/n;
    }

    return ans;
}



ll pow_mod(ll a, ll b, ll c) {
    if(!b)	return 1;

    ll ans = pow_mod(a, b/2, c);
    if(b % 2 == 0) ans = ans * ans % c;
    else ans = ans * ans % c * a % c;

    return ans;
}

int main() {
    ll a, c;
    string b;
    ios::sync_with_stdio(false);

    while(cin >> a >> b >> c) {
        int len = b.length();
        ll phi = getphi(c);
        ll bb = 0;
        int i;
        for(i = 0; i < len; i++) {
            bb = bb * 10 + b[i] - '0';
            if(bb > phi)	break;
        }

        if(i == len) {
            cout << pow_mod(a, bb, c) << endl;
        }
        else {
            bb = 0;
            for(int i = 0; i < len; i++) {
                bb = (bb * 10 + b[i] - '0') % phi;
            }

            cout << pow_mod(a, bb+phi, c) << endl;
        }
    }
}
