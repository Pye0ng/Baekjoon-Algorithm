#include<stdio.h>

int main(){
	int a, b, c, m, t;
	scanf("%d %d %d", &a, &b, &c);
	m=a<b?(a<c?a:c):(b<c?b:c);
	t=m; a-=m; b-=m; c-=m;
	if((a==0&&b==0)||(b==0&&c==0)||(c==0&&a==0)) printf("%d", t+(a+b+c+2)/3);
	else{
		if(b==0) b=a;
		else if(c==0){ c=b; b=a; }
		t+=b/3+c/3;
		b-=3*(b/3); c-=3*(c/3);
		if(b!=0&&c!=0) t+=b>c?b:c;
		else if((b!=0&&c==0)||(b==0&&c!=0)) t+=1;
		printf("%d", t);
	}
}
