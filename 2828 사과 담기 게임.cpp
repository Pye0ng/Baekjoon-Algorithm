#include<stdio.h>
int n, m, s, p=1, q, t;

int main(){
	scanf("%d %d %d", &n, &m, &t);
	while(t--){
		scanf("%d", &q);
		if(q<p){ s+=p-q; p=q; }
		else if(q>p+m-1){ s+=q-p-m+1; p=q-m+1; }
	}
	printf("%d", s); 
}
