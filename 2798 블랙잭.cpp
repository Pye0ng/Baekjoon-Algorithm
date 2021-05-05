#include<stdio.h>
int b[101];

int main(){
	int n, m, min=0, black;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++) scanf("%d", &b[i]);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			for(int k=1; k<=n; k++){
				if(i==j||j==k||k==i) continue;
				black=b[i]+b[j]+b[k];
				if(black<=m&&black>min) min=black;
			}
		}
	}
	printf("%d", min);
}

