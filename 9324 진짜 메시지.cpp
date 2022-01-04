#include<stdio.h>
char s[100010];
int m, a[30];

int main(){
	int t, i;
	scanf("%d", &t);
	while(t--){
		scanf("%s", s);
		for(i=0; s[i]!='\0'; i++){
			a[s[i]-'A']++;
			if(a[s[i]-'A']%3==0){
				if(s[i]!=s[i+1]) m=1;
				else i++;
			}
		}
		if(m) printf("FAKE\n");
		else printf("OK\n");
		for(i=0; i<100010; i++) s[i]='\0';
		for(i=0; i<30; i++) a[i]=0;
		m=0;
	}
}
