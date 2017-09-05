/********************************************************************
 * File Name: Easy_Problem_from_Rujia_Liu.cpp
 * Author: Sequin
 * mail: Catherine199787@outlook.com
 * Created Time: 二  9/ 5 18:01:49 2017
 *************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map <int, vector<int> > mm;

int main() {
    int n, m;
    while(cin >> n >> m) {
        mm.clear();
        for(int i = 1; i <= n; i++) {
            int t;
            cin >> t;
            if(mm.count(t) == 0)    mm[t] = vector<int>();
            mm[t].push_back(i);
        }

        for(int j = 0; j < m; j++) {
            int k, v;
            cin >> k >> v;
           // cout << mm[v].size();
            if(mm[v].size() < k || mm.count(v) == 0) cout << 0 << endl;
            else	cout << mm[v][k-1] << endl;
        }
    }
    return 0;

}
