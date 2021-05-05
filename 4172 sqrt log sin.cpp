#include<stdio.h>
#include<math.h>
int d[1000100];

int main(){
	int n, i;
	d[0]=1;
	for(i=1; i<=1000000; i++) d[i]=(d[(int)(i-sqrt(i))]+d[(int)log(i)]+d[(int)(i*sin(i)*sin(i))])%1000000;
	scanf("%d", &n);
	while(n!=-1){
		printf("%d\n", d[n]);
		scanf("%d", &n);
	}
}
