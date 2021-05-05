#include<stdio.h>
#include<algorithm>
int k, ar[500001];

bool bin_sc(int p){
	int m, a=0, b=p-1;
	while(b>=a){
		m=(a+b)/2;
		if(ar[m]==k) return 1;
		else if(ar[m]>k) b=m-1;
		else a=m+1;
	}
	return 0;
}

int main(){
	int n, m, i;
	scanf("%d", &n);
	for(i=0; i<n; i++) scanf("%d", &ar[i]);
	std::sort(ar, ar+n);
	scanf("%d", &m);
	for(i=0; i<m; i++){
		scanf("%d", &k);
		printf("%d ", bin_sc(n));
	}
}
