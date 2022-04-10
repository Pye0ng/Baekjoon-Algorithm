#include<stdio.h>
char n, s[1000100];

int main(){
	int s0=0, s1=0, i;
	scanf("%s", s); n=s[0];
	for(i=0; s[i]!='\0'; i++){
		if(s[i]!=n){
			if(n=='1') s1++;
			else s0++;
			n=s[i];
		}
	}
	if(n=='1') s1++;
	else s0++;
	printf("%d", s0<s1?s0:s1);
}
