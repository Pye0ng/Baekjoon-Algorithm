#include<stdio.h>
char c[52];

int main(){
	int t=0, i, j;
	scanf("%s", c);
	for(i=0; c[i]!='\0'; i++){
		if(c[i]=='X') t++;
		else{
			if(t%2){ printf("-1"); return 0; }
			t=0;
		}
	}
	if(t%2){ printf("-1"); return 0; }
	t=0;
	for(i=0; c[i]!='\0'; i++){
		if(c[i]=='X') t++;
		else{
			for(j=0; j<(t/4)*4; j++) printf("A");
			for(j=(t/4)*4; j<t; j++) printf("B");
			printf(".");
			t=0;
		}
	}
	for(j=0; j<(t/4)*4; j++) printf("A");
	for(j=(t/4)*4; j<t; j++) printf("B");
}
