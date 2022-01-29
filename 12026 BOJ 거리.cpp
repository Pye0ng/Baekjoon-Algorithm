#include<stdio.h>
int d[1010];
char c, s[1010];
int min(int a, int b){ return a<b?a:b; }

int main(){
	int n, i, j;
	scanf("%d", &n);
	scanf("%s", s); 
	for(i=1; i<n; i++){
		d[i]=1e8;
		if(s[i]=='B') c='J';
		if(s[i]=='O') c='B';
		if(s[i]=='J') c='O';
		for(j=0; j<i; j++)
			if(s[j]==c) d[i]=min(d[i], d[j]+(i-j)*(i-j));
	}
	if(d[n-1]==1e8) printf("-1");
	else printf("%d", d[n-1]);
}
