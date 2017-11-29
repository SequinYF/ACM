#include <cstdio>
#include <iostream>
#include <queue>
#include <algorithm>
#include <string.h>
int a[10005];
int hush[10005];
using namespace std;

int main(){
   ios::sync_with_stdio(false);

    int t;
    scanf("%d", &t);
    while(t--){
        bool tag = false;
        memset(a, 0, sizeof(a));
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            hush[a[i]] = i;
        }

        for(int i = 1; i <= n; i++){
            for(int j = i+1; j <= n; j++){
                int sum = a[i] + a[j];
                if(sum % 2){
                    continue;
                }

                if(hush[sum/2] > i && hush[sum/2] < j){
                    tag = true;
                    break;
                }
            }
            if(tag){
                break;
            }
        }

        printf("%c\n", tag ? 'Y' : 'N');
    }
}


