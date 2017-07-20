#include <iostream>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;

int main(){
    int n, t;
    int sum = 0;
    priority_queue<int> num;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> t;
        if (t <= 0){
          if(t % 2)
              num.push(t);
        }
        else{
          sum += t;
          if(t % 2)
              num.push(-t);
        }
    }

    if(sum % 2)
        cout << sum << endl;
    else
        cout<< sum + num.top() << endl;
        return 0;
}
