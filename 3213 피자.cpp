#include<stdio.h>
int a, b, c, t;

int main(){
	int n, p, q;
	scanf("%d", &n);
	while(n--){
		scanf("%d/%d", &p, &q);
		if(p*q==2) b++;
		else if(p*q==4) a++;
		else c++;
	}
	t+=c+(b+1)/2;
	if(b%2) a-=2;
	a-=c;
	if(a>0){
		if(a%4==0) t+=a/4;
		else t+=a/4+1;
	}
	printf("%d", t);
}
