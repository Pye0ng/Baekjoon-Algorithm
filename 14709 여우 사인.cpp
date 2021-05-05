#include<stdio.h>
int cnt, ch;

int main(){
	int n, i;
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		if(a==2||a==5||b==2||b==5) ch=1;
		if((a==1&&b==3)||(a==3&&b==1)||(a==1&&b==4)||(a==4&&b==1)||(a==3&&b==4)||(a==4&&b==3)) cnt++;
	}
	if(ch||cnt!=3) printf("Woof-meow-tweet-squeek");
	else printf("Wa-pa-pa-pa-pa-pa-pow!");
}
