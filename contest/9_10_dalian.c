#include <stdio.h>
#include <math.h>
#include <malloc.h>
#include <string.h>

#define MAX 10000
#define INF 0x7777777
//int[MAX]
/*
int main(){
	int day, drink;
	int i, j;
	int count = 0;
	int shop[MAX];
	int money[MAX];
	
	scanf("%d", &drink);

	for(i = 0; i < day; i++){
		scanf("%d", &shop[i]);
	}

	scanf("%d", &day);
	for(i = 0; i < day; i++){
		scanf("%d", &money[i]);
	}

	for(j = 0; j < day; j++){
		while(drink--){
			if(money[i] >= shop[drink]){
				count++;
			}
		}
		printf("%d\n", count);
		count = 0;
	}

}
*/

/*

int gcd(int a, int b){ 
   int c, m, n;   

   m = a;
   n = b;

   while(b)
   {
   		c=a%b;
   		a=b;  
   		b=c;
   	}
	printf("%d\n", a);
   	return a;
}
int calc(int n){
 	
 	int i, res = 2;//1 和自身
  
 	if(n == 1)
 		return 1;
  
 	for(i = 2; i*i <= n; i++)
  		if(n%i == 0){
   			if(n == i*i)
   				res+=1;
   			else 
   				res+=2;
  		}
 		return res;
}

int main(int argc, char ** argv){

	int N, Q;
	int i;
	int n[MAX], q[MAX][2];
	int start, temp;

  	scanf("%d %d", &N, &Q);

  	for(i = 0; i < N; i++){
  		scanf("%d", &n[i]);
  	}

  	for(i = 0; i < Q; i++){
  		scanf("%d %d", &q[i][0], &q[i][1]);
  	}

  	for( i = 0; i < Q; i++){
  		temp = n[ q[i][0] ];

  		for(start = q[i][0]; start < q[i][1]; start++){	
  			temp = gcd(temp, n[start]);
  		}
 		
 		printf("%d %d\n", temp ,calc(N));
  	} 		
 	return 0;
}

*/




void calc(int n, int res[]){
 	
 	int i;

 	for(i = 1; i*i <= n; i++)

  		if(n%i == 0){
   			
        if(n == i*i)
   				res[i] = 1;
   			
        else {
   				res[i] = 1;
          res[n/i] = 1;
  		  }
    }
}

int main(int argc, char ** argv){

	int N, Q;
	int i, j;
	int n[MAX], q[MAX][2];
	int start, count = 0;
  int res[MAX];

  memset(res, 0, sizeof(MAX));

  scanf("%d %d", &N, &Q);

  for(i = 1; i <= N; i++){
  	scanf("%d", &n[i]);
  }

  for(i = 1; i <= Q; i++){
  	scanf("%d %d", &q[i][0], &q[i][1]);
  }

  for(i = 1; i <= Q; i++){
  	for(start = q[i][0]; start < q[i][1]; start++){	
  		  calc(n[start], res);
  	}
 		
    for(j = 1; j <= n[start]; j++){
      if(res[j]){
        count++;
      }
    }

    memset(res, 0, sizeof(MAX));
 		printf("%d\n", count);

    count = 0;
  } 		


 	return 0;
}


