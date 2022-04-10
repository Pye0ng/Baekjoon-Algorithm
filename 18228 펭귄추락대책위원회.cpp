#include<stdio.h>

int main(){
	int n, t, c, m=1e9+1, i;
	scanf("%d", &n); 
	for(i=0; i<n; i++){
		scanf("%d", &t);
		if(t==-1){ c=m; m=1e9+1; }
		else if(t<m) m=t;
	}
	printf("%d", c+m);
}
