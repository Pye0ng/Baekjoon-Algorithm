#include<stdio.h>
int main(){
	int sum=0, t, i;
	for(i=0; i<5; i++){
		scanf("%d", &t);
		if(t<40) t=40;
		sum+=t;
	}
	printf("%d", sum/5);
}
