#include<stdio.h>
int sum;
int a[1001];
 
void prime(){
	int i;
	for(i=2; i<=1000; i++) a[i]=1;
	for(i=2; i<=1000; i++){
		if(a[i]==0) continue;
		for(int j=2*i; j<=1000; j+=i) a[j]=0;
	}
}

bool check(int k){
	int i;
	for(i=2; i<=1000; i++){ if(a[k]) return 1; }
	return 0;
}

int main(){
	int n, k, i;
	prime();
	scanf("%d", &n);
	for(i=0; i<n; i++){
		scanf("%d", &k);
		if(check(k)) sum++;
	}
	printf("%d", sum);
}
