#include <iostream>
#include <cstdio>
#include <cstring>
#define ll long long
using namespace std;


ll gcd(ll m,ll n){
    return n == 0 ? m : gcd(n, m % n);
}

ll lcm(ll m,ll n){
    return m / gcd(m, n) * n;
}

int main(){

    int t;
    cin >> t;
    while(t--){
        ll a, b, c, d;
        scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
        ll t;
        t = gcd(a, b);
        a /= t;
        b /= t;
        t = gcd(c, d);
        c /= t;
        d /= t;
        if(gcd(b, d) == 1)
            printf("%lld\n", lcm(a, c));
        else
            printf("%lld/%lld\n", lcm(a, c), gcd(b, d));
    }
    return 0;
}
