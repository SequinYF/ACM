#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#define MAX 0xfffffff


//D

int main(){
	int n, i, j;
	long long temp = 1, num;
	long long answ = 1;

	scanf("%d", &n);
	while(n--){
		scanf("%d", &num);
		temp = temp * num;
	}
	for(i = 1; i <= sqrt(temp); i++){
		if(temp % i == 0){
			if(i  == (temp / i)){
				answ *= i;
			}
			else{
				answ *= i * (temp / i);
			}
			answ = answ % MAX;
		}
	}
	printf("%I64d", answ);

	return 0;
}



//A
/*
int main()
{
	int bulbs,button;
	int b[101]={0};
	int k,i,t,j;

	scanf("%d %d",&button,&bulbs);

	for(i=0;i<button;i++)
	{
	        scanf("%d",&k);
		for(j=0;j<k;j++)
		{
			scanf("%d",&t);
			b[t]=1;
		}
	}
	for(i=1;i<=bulbs;i++)
	{
		if(b[i]==0)
		{
			break;
		}
	}
	if(i>bulbs)
	{
		printf("YES\n");
	}
	else
	{
		printf("NO\n");
	}
	return 0;
}
*/