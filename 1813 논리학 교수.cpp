#include<stdio.h>
int d[52];

int main(){
	int n, t, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &t);
		d[t]++;
	}
	t=-1;
	for(i=0; i<51; i++) if(d[i]==i) t=i;
	printf("%d", t);
}
