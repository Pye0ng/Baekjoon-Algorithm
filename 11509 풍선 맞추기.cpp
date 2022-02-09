#include<stdio.h>
int cnt, d[1000100];

int main(){
	int n, t, i;
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &t);
		if(d[t+1]) d[t+1]--;
		else cnt++;
		d[t]++;
	}
	printf("%d", cnt);
}
