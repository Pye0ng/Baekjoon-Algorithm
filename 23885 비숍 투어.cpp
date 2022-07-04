#include<stdio.h>

int main(){
	int a, b, c, d, e, f;
	scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
	printf("%s", ((c&1)^(d&1))==((e&1)^(f&1))&&((a!=1&&b!=1)||(c==e&&d==f))?"YES":"NO");
}
