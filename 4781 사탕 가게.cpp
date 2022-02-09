#include<stdio.h>
#define max(x, y) x>y?x:y
int w[5050], v[5050], d[10100];

int main(){
	int n, k, i, j;
	double m;
	scanf("%d %lf", &n, &m);
	while(n!=0){
		m+=0.005; k=(int)(m*100);
		for(i=1; i<=n; i++){
			scanf("%d %lf", &v[i], &m);
			m+=0.005; w[i]=(int)(m*100);
		}
		for(i=1; i<=n; i++)
			for(j=1; j<=k; j++)
				if(j>=w[i]) d[j]=max(d[j], d[j-w[i]]+v[i]);
		printf("%d\n", d[k]);
		for(i=1; i<=k; i++) d[i]=0;
		scanf("%d %lf", &n, &m);
	}
}
