#include<stdio.h>
int n, x, y, cnt;

void find(int d[], int k){
	if(k==y-x-1){
		if(k==n) cnt++;
		else find(d, k+1);
	}
	else{
		for(int i=1; i<2*n-k; i++){
 			if(d[i]==0&&d[i+k+1]==0){
				if(k==n){
					cnt++;
					return;
				}
				d[i]=d[i+k+1]=k;
				find(d, k+1);
				d[i]=d[i+k+1]=0;
			}
		}
	}
}

int main(){
	int i, d[25]={};
	scanf("%d %d %d", &n, &x, &y);
	d[x]=d[y]=y-x-1;
	if(y-x-1>n){
		printf("0");
		return 0;
	}
	find(d, 1);
	printf("%d", cnt);
} 
