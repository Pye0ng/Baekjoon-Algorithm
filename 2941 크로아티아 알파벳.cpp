#include<stdio.h>
#include<string.h>
int k, i;
char s[101];

int main(){
	scanf("%s", s);
	for(i=0; i<strlen(s); i++){
		if(s[i]=='c'&&(s[i+1]=='='||s[i+1]=='-')) i++;
		else if(s[i]=='d'){
			if(s[i+1]=='z'&&s[i+2]=='=') i+=2;
			else if(s[i+1]=='-') i++;
		}
		else if(s[i+1]=='j'&&(s[i]=='l'||s[i]=='n')) i++;
		else if(s[i+1]=='='&&(s[i]=='s'||s[i]=='z')) i++;
		k++;
	}
	printf("%d", k);
}
