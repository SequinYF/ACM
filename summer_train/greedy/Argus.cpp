/********************************************************************
* File Name: Argus_cpp
* Author: Sequin
* mail: Catherine199787@outlook.com
* Created Time: 二  9/ 5 18:45:19 2017
*************************************************************************/

#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
#define ll long long

struct node {
    ll num;
    ll period;
    ll time;

    bool operator < (const node &a) const{
        if(a.time == time) {
            return a.num < num;
        }
        return a.time < time;
    }
};


priority_queue <node> pq;

int main() {
    string s;
    node t;

    while(cin >> s && s != "#") {
        cin >> t.num  >> t.time;
        t.period = t.time;
        pq.push(t);
    }

    int k;
    cin >> k;
    for(int i = 0; i < k; i++) {
        node now;
        now = pq.top();
        cout << now.num << endl;
        pq.pop();
        now.time += now.period;
    //    cout << now.time << endl;
        pq.push(now);
    }
    return 0;
}


