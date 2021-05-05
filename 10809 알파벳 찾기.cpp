#include<stdio.h>
#include<string.h>
char s[101];
int a[27];

int main(){
	int i;
	scanf("%s", s);
	for(i=0; i<26; i++) a[i]=-1;
	for(i=0; i<strlen(s); i++){
		if(a[s[i]-97]!=-1) continue; 
		a[s[i]-97]=i;	
	}
	for(i=0; i<26; i++) printf("%d ", a[i]);
}
