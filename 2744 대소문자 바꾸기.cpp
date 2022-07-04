#include<stdio.h>
char c[110];

int main(){
	scanf("%s", c);
	for(int i=0; c[i]!='\0'; i++){
		if(c[i]<='Z') c[i]+=32;
		else c[i]-=32;
	}
	printf("%s", c);
}
