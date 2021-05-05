#include<stdio.h>
char s[1001][21];
int d[1001];

int main(){
	int i, t;
	scanf("%d", &t);
	for(i=0; i<t; i++) scanf("%d %s", &d[i], s[i]);
	for(i=0; i<t; i++){
		for(int j=0; s[i][j]!='\0'; j++){
			for(int k=1; k<=d[i]; k++) printf("%c", s[i][j]);
		}
		printf("\n");
	}
} 
