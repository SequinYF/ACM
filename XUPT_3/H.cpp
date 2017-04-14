#include <stdio.h>
#include <string.h>
#define base 500000

int hash_[1000001] = {0};

int main(){

    int n, m;
    while(scanf("%d%d", &n, &m) == 2){
        memset(hash_, 0, sizeof(hash_));
        for(int i = 0; i < n; i++){
            int temp;
            scanf("%d", &temp);
            hash_[base+temp] = 1;
        }

        int mm = m;
        for(int i = 1000000; i > 0; i--){
            if(hash_[i] > 0){
                m--;
                if(mm-1 == m)
                    printf("%d", i - base);
                else{
                    printf(" %d", i - base);
                }
            }
            if(!m){
                printf("\n");
                break;
            }
        }

    }
    return 0;
}
