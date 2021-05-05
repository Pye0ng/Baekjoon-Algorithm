#include<stdio.h>
int n, k, cnt;

void plus(int sum){
	if(sum==k){
		cnt++;
		return;
	}
	for(int i=1; i<=3; i++)
		if(sum+i<=k) plus(sum+i);
}

int main(){
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		cnt=0;
		scanf("%d", &k);
		plus(0);
		printf("%d\n", cnt);
	}
}
