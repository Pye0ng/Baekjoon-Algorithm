#include<stdio.h>
#include<string.h>
char c[51];

bool ch(){
	int a=0;
	if(c[0]==41&&c[strlen(c)-1]==40) return 1;
	for(int i=0; i<strlen(c); i++){
		if(c[i]==40) a++;
		else a--;
		if(a<0) return 1;
	}
	return a!=0;
}

int main(){
	int n;
	scanf("%d", &n);
	for(int i=1; i<=n; i++){
		scanf("%s", c);
		if(ch()) printf("NO\n");
		else printf("YES\n");
	}
}
