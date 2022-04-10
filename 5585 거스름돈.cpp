#include<stdio.h>
int main(){
	int t, a=0;
	scanf("%d", &t);
	t=1000-t;
	a+=t/500; t-=(t/500)*500;
	a+=t/100; t-=(t/100)*100;
	a+=t/50; t-=(t/50)*50;
	a+=t/10; t-=(t/10)*10;
	a+=t/5; t-=(t/5)*5;
	a+=t;
	printf("%d", a);
}
