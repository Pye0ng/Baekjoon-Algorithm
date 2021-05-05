#include<stdio.h>
int min(int x, int y){ return x<y?x:y; }
int a[1010], b[1010], c[1010], d[1010][4];

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++) scanf("%d %d %d", &a[i], &b[i], &c[i]);
	d[1][1]=a[1]; d[1][2]=b[1]; d[1][3]=c[1];
	for(i=2; i<=n; i++){
		d[i][1]=min(d[i-1][2], d[i-1][3])+a[i];
		d[i][2]=min(d[i-1][1], d[i-1][3])+b[i];
		d[i][3]=min(d[i-1][1], d[i-1][2])+c[i];
	}
	printf("%d", min(d[n][1], min(d[n][2], d[n][3])));
}
