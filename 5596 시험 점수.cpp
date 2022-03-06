#include<stdio.h>

int main(){
	int a, s1=0, s2=0, i;
	for(i=0; i<8; i++){
		scanf("%d", &a);
		if(i<4) s1+=a;
		else s2+=a;
	}
	printf("%d", s1<s2?s2:s1);
}
