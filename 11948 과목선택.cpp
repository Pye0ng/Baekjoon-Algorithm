#include<stdio.h>

int main(){
	int s=0, a, m1=101, m2=101, i;
	for(i=0; i<6; i++){
		scanf("%d", &a);
		if(i<4) m1=a<m1?a:m1; 
		else m2=a<m2?a:m2;
		s+=a;
	}
	printf("%d", s-m1-m2);
}
