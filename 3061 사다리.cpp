#include<stdio.h>
int d[1010];

int main(){
	int t, n, s, i, j;
	scanf("%d", &t);
	while(t--){
		scanf("%d", &n); s=0;
		for(i=0; i<n; i++) scanf("%d", &d[i]);
		for(i=0; i<n; i++)
			for(j=i; j<n; j++) s+=d[i]>d[j];
		printf("%d\n", s);
	}
}
