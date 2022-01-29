#include<stdio.h>
int n, t, s, m;


int main(){
	scanf("%d", &n);
	while(n--){
		scanf("%d", &t);
		if(t>m) m=t;
		s+=t;
	}
	printf("%d", s-m);
}
