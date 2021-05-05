#include<stdio.h>
#include<string.h>
char s[1000001];
int a[129];

int main(){
	int i, max=0, point, ch=0;
	scanf("%s", s);
	for(i=0; i<strlen(s); i++){
		if(s[i]<='Z') a[s[i]-'A']++;
		else a[s[i]-'a']++;
	} 
	for(i=1; i<26; i++){
		if(a[i]>max){
			max=a[i];
			point=i;
			ch=0;
		}
		if(a[i]==max) ch++;
	}
	if(ch>=2) printf("?");
	else printf("%c", point+'A');
}
