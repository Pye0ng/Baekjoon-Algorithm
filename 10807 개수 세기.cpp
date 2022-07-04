#include<stdio.h>
int d[210];

int main(){
	int n, t;
	scanf("%d", &n);
	while(n--){
		scanf("%d", &t);
		d[t+100]++;
	}
	scanf("%d", &t);
	printf("%d", d[t+100]);
}
