#include<stdio.h>
int min(int a, int b){ return a<b?a:b; }

int main(){
	int t=1, l, p, v;
	scanf("%d %d %d", &l, &p, &v); 
	while(l){
		printf("Case %d: %d\n", t++, l*(v/p)+min(v-p*(v/p), l));
		scanf("%d %d %d", &l, &p, &v);
	}
}
