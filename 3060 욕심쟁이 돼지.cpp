#include<stdio.h>
int t, n, pg[7], d[7];

long long int greed(int k){
	long long int sum=pg[k]+pg[(k+5)%6]+pg[(k+1)%6]+pg[(k+3)%6];
	d[k]=sum;
	return sum;
}

int main(){
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
		long long int sum=0, cnt=1;
		scanf("%d", &n);
		for(int j=0; j<6; j++){
			scanf("%d", &pg[j]);
			sum+=pg[j];
		}
		while(sum<=n){
			sum=0;
			for(int j=0; j<6; j++) sum+=greed(j);
			for(int j=0; j<6; j++) pg[j]=d[j];
			cnt++;
		}
		printf("%d\n", cnt);
	}
}
