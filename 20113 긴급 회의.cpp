#include<stdio.h>
int i, n, k, d[101];
int max, out;

int main(){
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		scanf("%d", &k);
		d[k]++;
	}
	for(i=1; i<=n; i++)
		if(d[i]>max) max=d[i];
	for(i=1; i<=n; i++){
		if(d[i]==max){
			if(out==0) out=i;
			else{
				printf("skipped");
				return 0;
			}
		}
	}
	printf("%d", out);
}
