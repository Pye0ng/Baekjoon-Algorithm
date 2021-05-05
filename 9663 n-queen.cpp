#include<stdio.h>
#include<math.h>
int n, cnt;
int d[17];

bool check(int k){
	for(int i=0; i<k; i++)
		if(d[i]==d[k]||abs(d[k]-d[i])==k-i) return false;
	return true;
}

void queen(int k){
	if(k==n) cnt++;
	else{
		for(int i=0; i<n; i++){
			d[k]=i;
			if(check(k)) queen(k+1);
		}
	} 
}

int main(){
	int i, j;
	scanf("%d", &n);
	queen(0);
	printf("%d", cnt);
}
