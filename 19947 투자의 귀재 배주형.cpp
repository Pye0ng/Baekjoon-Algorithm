#include<stdio.h>
int x, y, m;

void i(int s, int t){
	if(t==0){
		if(s>m) m=s;
		return;
	}
	i(s*1.05, t-1);
	if(t>2) i(s*1.2, t-3);
	if(t>4) i(s*1.35, t-5);
}

int main(){
	scanf("%d %d", &x, &y);
	i(x, y);
	printf("%d", m);
}
